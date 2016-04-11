// Author Chengeng Xiao 2016.03.29
// ECS50 HW1
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

typedef union{
	float f;
	unsigned int fn;
} FFF; // union FFF Float_For_Format

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
    cout << "1.";
    // sign and before decimal point

    unsigned buf = n;
    for(int i = 0; i< 23 ; ++i){
        buf <<=1;
        if (buf & 0x0800000)
            bitwise.append("1");
        else // else
            bitwise.append("0");
    } // for(): calc for 23 bits

    for (string::iterator itr = bitwise.end() - 1; *itr == '0'; itr--)
        bitwise.pop_back();
    cout << bitwise;
    // bitwise number

    cout << "E";
    int exp = (n >> 23) & 0xff;
    exp -= 127; //bias 127
    cout << exp << endl;
    // exponent number

	return 0;
} // main()
