/*
 * CALC -- program to implement a simple arithmetic calculator
 *
 * Usage: calc
 *
 * Inputs (from standard input)
 *      -- operator, one of + - * / %
 *      -- 2 operands, both integers
 *
 * Exit Code: 0 if all is well, 1 on error
 *
 * written for ECS 030, Fall 2015
 * 
 * Matt Bishop, Sept. 24, 2015
 *      original program written
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * MACROS
 *
 * These are to encode the operations
 */
#define	ERROR		0		/* unknown operation */
#define	ADD		1		/* addition operation */
#define	SUBTRACT	2		/* subtraction operation */
#define	MULTIPLY	3		/* multiplication operation */
#define	DIVIDE		4		/* division operation */
#define	REMAINDER	5		/* modulus operation */


/*
 * GETOP -- get an integer operand; we do operation-specific checks later
 *
 * parameters: opno	the number of the operand (as in 1st, 2nd, etc.)
 * returns: int		the integer value of the operand just read
 * exceptions: none
 */
int getop(int opno)
{
	char *readVal;
	int val;		/* value read */
	int rv = 1;			/* value returned from scanf */

	/*
 	 * loop until you get an integer or EOF
 	 */
 	 readVal = malloc(sizeof(char)*20);
	do{
		/* prompt and read a value */
		printf("\toperand %d: ", opno);
		scanf("%s", readVal);
		/* oops ... bogus value */
		if (strcmp(readVal,"0") == 0){
			val = 0;
			break;
		}
		if (atoi(readVal) == 0){
			printf("\toperand must be an integer\n");
			continue;
		}
		else {
			val = atoi(readVal);
			break;
		}

		/* loop until a valid value */
	} while (1);

	/*
 	 * if it's EOF, say so and quit
 	 */
	if (rv == EOF)
		exit(EXIT_SUCCESS);

	/*
 	 * otherwise, say what you read
 	 */
	return(val);
}

/*
 * VALOP -- return value of operation
 *
 * parameters: int	a character representing the operator
 * returns: int		operator code (see above) or ERROR 
 * exceptions: none
 */
int valop(int op)
{
	switch(op){		/* map character into code */
	case '+':    return(ADD);
	case '-':    return(SUBTRACT);
	case '*':    return(MULTIPLY);
	case '/':    return(DIVIDE);
	case '%':    return(REMAINDER);
	}

	/*
	 * unknown character -- balk
	 */
	return(ERROR);
}

/*
 * ISDIVOP -- return 1 if argument is a division operator
 *
 * parameters: int	a character representing the operator
 * returns: int		1 if argument is '/' or '%', 0 otherwise
 * exceptions: none
 */
int isdivop(int op)
{
	return(op == DIVIDE || op == REMAINDER);
}

/*
 * APPLY -- perform desired calculation
 *
 * parameters: int	first operand
 *             int	second operand
 *             int	operation
 *             ***** assume: if operation is a division one, the
 *             ***** second operand is non-zero
 * returns: int		result
 * exceptions: none
 */
int apply(int op1, int op, int op2)
{
	int answer;			/* the answer */

	/*
	 * do the operation or complain
	 */
	switch(op){
	case ADD:		/* add them */
		answer = op1 + op2;
		break;
	case SUBTRACT:		/* subtract second from first */
		answer = op1 - op2;
		break;
	case MULTIPLY:		/* multiply them */
		answer = op1 * op2;
		break;
	case DIVIDE:		/* divide first by second */
		answer = op1 / op2;
		break;
	case REMAINDER:		/* remainder when first divided by second */
		answer = op1 % op2;
		break;
	default:		/* should never happen ... */
		printf("Internal inconsistency: bad operator %d in apply\n", op);
		exit(EXIT_FAILURE);
	}

	/*
	 * now return the answer
	 */
	return(answer);
}
		
/*
 * the main routine -- start here
 */
int main(void)
{
	char *s;
	int ch;			/* input character */
	int op;			/* operation, derived from ch */
	int op1, op2;		/* operands */
	int result;		/* result to be printed */


	/*
	 * prompt the user for an operation
	 */
	printf("operation (+,-,*,/,%%)> ");
	s = (char*)malloc(sizeof(char)*100);
	/*
	 * loop until user says to quit
	 */
	while(scanf("%s",s) != EOF){
		/* convert the character read to an operator */
		if(strlen(s) > 1) {
			fprintf(stderr, "invalid operator %s\n", s);
			printf("operation (+,-,*,/,%%)> ");
			continue;
		}
		else 
			ch = s[0];
		if(ch == '\n') {
			printf("operation (+,-,*,/,%%)> ");
			continue;
		}
		if ((op = valop(ch)) == ERROR){
			fprintf(stderr, "invalid operator %c\n", ch);
			printf("operation (+,-,*,/,%%)> ");
			continue;
		}
		/* get the operands */
		op1 = getop(1);
		op2 = getop(2);
		getchar(); // get the '\n'
		/*
		 * if division operation by 0, complain
		 * otherwise do the operation
		 */
		if (isdivop(op) && op2 == 0)
			fprintf(stderr, "Can't have a denominator of 0\n");
		else{
			result = apply(op1, op, op2);
			printf("%d %c %d = %d\n", op1, ch, op2, result);
		}
		/* prompt again */
		printf("operation (+,-,*,/,%%)> ");
	}
	/*
	 * make it look nice
	 */
	putchar('\n');

	/*
	 * that's all, folks!
	 */
	return(EXIT_SUCCESS);
}