#include <stdio.h>
#include <stdlib.h>

void good_div(unsigned int dividend, unsigned int divisor, unsigned int* quotient, unsigned int *remaind)
{
    if (dividend < divisor)
    {
    	*quotient = 0;
    	*remaind = dividend;
    	return;
    }

    if (dividend == divisor)
    {
    	*quotient = 1;
    	*remaind = 0;
    	return;
    }

    *quotient = 0;
    *remaind = 0;

    for (int i = 0; i < 32; ++i)
    {
        (*quotient) <<= 1;
        (*remaind) <<= 1;

    	if ((dividend & 0x80000000) != 0)
    		(*remaind)++;
    	if ((*remaind) >= divisor)
    	{
    		(*remaind) -= divisor;
            (*quotient)++;
    	}
        dividend <<= 1;
    }
} /* good_div() */

int main(int argc, char* argv[])
{
	unsigned int dividend, divisor;
	unsigned int *quotient = malloc(sizeof(unsigned int)), *remaind = malloc(sizeof(unsigned int));
	dividend = atoi(argv[1]);
	divisor = atoi(argv[2]);
	good_div(dividend, divisor, quotient, remaind);
	printf("%u / %u = %u R %u \n", dividend, divisor, *quotient, *remaind);
	return 0;
} /* main() */