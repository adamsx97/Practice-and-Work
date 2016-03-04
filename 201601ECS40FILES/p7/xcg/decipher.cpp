#include <algorithm>
#include <streambuf>
#include <iostream>
#include <iterator>
#include <fstream>
#include <sstream>
#include <cstring>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class Likelihood
{
public:
    int iShift;
    int iLikelihood;
    bool operator< (const Likelihood& likelihood) const
    {

        if (likelihood.iLikelihood < this->iLikelihood)
            return true;
        return false;
    } // reload
}; // class

void shift(string& str, const int ShiftNumber)
{

    for (unsigned int i = 0; i < str.length(); i++)
    {

        if (isalpha(str.at(i)) && isupper(str.at(i)))
        {
            str.at(i) = 'A' + ((str.at(i) - 'A' + ShiftNumber + 26) % 26);
        } // if isupper

        if (isalpha(str.at(i)) && islower(str.at(i)))
        {

            str.at(i) = 'a' + ((str.at(i) - 'a' + ShiftNumber + 26) % 26);
        } // if islower
    } // find shift number

    return ;
} // shift

void openFile(vector<int> &frequencyyyy)
{
    ifstream fi;
    fi.open("frequencies");

    for (int i = 0; i < 26; i++)
        fi >> frequencyyyy.at(i);
    return ;
} // openfile

void findLikelihood(vector<Likelihood> &VLikelyhood, const vector<int> &VCount,
                    const vector<int> &Vfrequency)
{

    for(int iShift = 0; iShift < 26; ++ iShift)
    {

        Likelihood& likelihood = VLikelyhood.at(iShift);
        likelihood.iShift = iShift;
        likelihood.iLikelihood = 0;

        for (int c = 0; c < 26; c++)
        {
           likelihood.iLikelihood += VCount.at((c + iShift) % 26)
                                     * Vfrequency.at(c);

        } // for

    } // calculate likelihood
    
    return ;
} // shift

void output(const string &str, const vector<Likelihood> &vLikelyhood,
            const int i)
{
    ifstream finword; finword.open("words"); stringstream ss;
    ss << finword.rdbuf(); string word = ss.str(); string buff = "";
    bool Valid = true; buff = "";

    for (unsigned int j = 0; j < str.length(); j++)
    {

        if (isalpha(str.at(j)))
            buff += tolower(str.at(j));
        else // else
        {

            if (buff.empty())
               buff = "";
            else // else
            {  
                buff = "\n" + buff + "\n";

                if (word.find(buff) == string::npos)
                {
                    Valid = false;
                    break;
                } // if
                else // else
                    buff = "";
            } // else
        } // else
    } // for

    if (Valid == true)
        cout << "Deciphered message version #" << i << endl << str << endl;
    buff = "";
    
    return ;
} // output

int main(int argc, char** argv)
{
    vector<int> frequency(26, 0);
    vector<Likelihood> vLikelyhood(26);
    vector<int> vCount(26, 0);
    openFile(frequency);
    ifstream fin;
    fin.open(argv[1]);
    stringstream ss;
    ss << fin.rdbuf();
    string strEnc = ss.str();

    for (int i = 0; i < 26; i++)
        vCount.at(i) = count(strEnc.begin(), strEnc.end(), i + 'A') +
                       count(strEnc.begin(), strEnc.end(), i + 'a');

    findLikelihood(vLikelyhood, vCount, frequency);
    sort(vLikelyhood.begin(), vLikelyhood.end());

    for (int i = 1; i <= 26; i++)
    {
        shift(strEnc, -vLikelyhood.at(i - 1).iShift);
        output(strEnc, vLikelyhood, i);
        shift(strEnc, vLikelyhood.at(i - 1).iShift);
    } // for each case

    return 0;
} // main
