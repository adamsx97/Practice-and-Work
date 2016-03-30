// Author Chengeng Xiao 2016.03.29
// ECS50 HW1
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

typedef union{
	float f;
	unsigned int fn;
} FFF; // union FFF

int main(void)
{
	float f;
	unsigned n = 0;
	FFF fff;
    string bitwise;

	cout << "Please enter a float: ";
	cin >> f;

    if (f == 0)
    {
        cout << "0E0\n";
        return 0;
    } // special case

	fff.f = f;
	n = fff.fn;

    if(n & 0x80000000)
        cout << '-';
    unsigned bit = n & 0x07FFFFF;
    cout << "1.";
    // sign and before decimal point

    for(int i = 0; i< 23 ; ++i){
        bit <<=1;
        if (bit & 0x0800000)
            bitwise.append("1");
        else // else
            bitwise.append("0");
    } // for()
    for (string::iterator itr = bitwise.end() - 1; *itr == '0'; itr--)
        bitwise.pop_back();
    cout << bitwise;
    // bitwise number

    cout << "E";
    int exp = (n >> 23) & 0x0FF;

    exp -= 127; //bias 127
    if(exp < 0)
    {
        cout << '-';
        exp = -exp;
    } // if()
    // exponent sign

    int i = 0;

    while((exp & 0x080) == 0 && i < 8)
    {
        exp <<= 1;
        ++i;
    } // skip zero of top

    int expo = 0;

    if(i == 8)
   		cout << '0';
    for(;i< 8 ; ++i){
        if(exp & 0x080)
            expo += pow(2, 7 - i);
        exp <<=1;
    }
    cout << expo << endl;
    // exponent number

	return 0;
} // main()
