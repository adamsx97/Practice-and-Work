/*
 ID: nyyl1303
 LANG: C++
 TASK: beads
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

int pick(string exnecklace, int length, int picpoint)
{
    int left = 0, right = 0, s;
    if (exnecklace[picpoint] != 'w')
    {
        for (int i = 0; i < length; i++)
        {
            if (exnecklace[picpoint + i] != exnecklace[picpoint] && exnecklace[picpoint + i] != 'w')
                break;
            left++;
        }
    }
    else
    {
        s = 0;
        while(exnecklace[picpoint + s] == 'w' && s < length) s++;
        if (s == length)
            return length;
        for (int i = 0; i < length; i++)
        {
            if (exnecklace[picpoint + i] != exnecklace[picpoint + s] && exnecklace[picpoint + i] != 'w')
                break;
            left++;
        }
    }
	for (int i = 0; i < length - left; i++)
    {
        if (exnecklace[picpoint + left + i] != exnecklace[picpoint + left] && exnecklace[picpoint + left + i] != 'w')
            break;
        right++;
    }
    return left + right;
} // find continuousBeads

int main(void)
{
    int length = 123, max = -1;
    string necklace = "";
    ifstream fin("beads.in");
    ofstream fout("beads.out");
    
    fin >> length;
    fin >> necklace;
    necklace += necklace.substr(0, length-1);
    //fout << necklace << endl;
    for (int i = 0; i < length; i++)
    {
        //cout << " The " << i << " time： " << endl;
        max = max > pick(necklace, length, i) ? max : pick(necklace, length, i);
    }
    
    fout << max << endl;
    return 0;
}