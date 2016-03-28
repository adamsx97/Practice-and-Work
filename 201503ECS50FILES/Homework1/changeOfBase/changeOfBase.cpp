// Author Chengeng Xiao 2016.03.28
// ECS50 HW1
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

typedef string::iterator SIT;

int charToInt(char a)
{
    if (a > '9')
        return a - 'A' + 10;
    else
        return a - '0';
    
} // charToInt()

char intToChar(int a)
{
    if (a >= 10)
        return 'A' + a - 10;
    else
        return '0' + a;
} // intToChar()

int main(void)
{
    int rb, nb, num = 0, l, t; // rb:RawBase, nb:NewBase, l:length
    string rn, nn; // rn:RawNum, nn:NewNum
    
    cout << "Please enter the number's base: ";
    cin >> rb;
    cout << "Please enter the number: ";
    cin >> rn;
    cout << "Please enter the new base: ";
    cin >> nb;
    
    l = (int)rn.length();
    int i = l - 1;
    for (SIT itr = rn.begin(); itr != rn.end(); itr++)
    {
        t = charToInt(*itr);
        num += t * (int)pow((float)rb, i--);
    } // for(): turn other base into ten base

    int rm; // rm:remainder
    char buf; // buffer
    while (num > 0)
    {
        rm = num % nb;
        buf = intToChar(rm);
        nn.insert(0, 1, buf);
        num /= nb;
    } // while(): change ten base num into aiming base
    
    cout << rn << " base " << rb << " is " << nn << " base " << nb << endl;
    return 0;
} // main()
