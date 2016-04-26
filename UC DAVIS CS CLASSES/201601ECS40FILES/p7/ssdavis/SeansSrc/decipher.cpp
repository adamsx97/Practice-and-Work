// Author: Sean Davis 
// Created on February 23, 2016, 10:07 AM

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <sstream>
using namespace std;

class Likelihood 
{
public:
  int shift;
  int likelihood;
  bool operator < (const Likelihood &rhs) const 
  { return likelihood > rhs.likelihood; 
  }  // operator<
};  // class Likelihood

void readFrequencies(vector<int> *frequencies)
{
  ifstream inf("frequencies");
  
  for(int i = 'a'; i <= 'z'; i++)
    inf >> frequencies->at(i - 'a');
}  // readFrequencies()

void readFile(const char *filename, string *fileString, vector<int> *counts)
{
  double total = 0;
  ifstream inf(filename);
  stringstream strStream;
  strStream << inf.rdbuf();  //read the file
  *fileString = strStream.str();  //str holds the content of the file

  for(char letter = 'a'; letter <= 'z'; letter++)
    total += counts->at(letter - 'a') 
      = count(fileString->begin(), fileString->end(), letter)
      + count(fileString->begin(), fileString->end(), letter - ('a' - 'A'));
    
} // readFile()


void setLikelihoods(const vector<int> &frequencies, 
                    const vector<int> &counts, vector<Likelihood> *likelihoods)
{
  for(int shift = 0; shift < 26; shift++)
  {
    likelihoods->at(shift).shift = shift;
    likelihoods->at(shift).likelihood = 0;
    
    for(int letter = 0; letter < 26; letter++)
      likelihoods->at(shift).likelihood += frequencies.at(letter) 
        * counts.at((letter + shift) % 26);
  } // for each shift 
  
  sort(likelihoods->begin(), likelihoods->end());
} //setLikelihood()


void writeVersions(const string &fileString, 
                   const vector <Likelihood> &likelihoods)
{
  
  for(int pos = 0; pos < 6; pos++)
  {
    cout << "Deciphered message version #" << pos + 1 << endl;
    
    for(string::const_iterator sitr = fileString.begin(); 
      sitr != fileString.end(); sitr++)
    {
      if(islower(*sitr))
        cout << (char) ((*sitr - 'a' - likelihoods.at(pos).shift + 26) % 26 
          + 'a');
      else  // not lowercase letter
        if(isupper(*sitr))
          cout << (char) ((*sitr - 'A' - likelihoods.at(pos).shift + 26) % 26 
            + 'A');
        else // not letter, so must be a space
          cout << *sitr;
    } // for each char in string

    cout << endl;
  } // for each version 
}  // writeVersions()


int main(int argc, char** argv) 
{
  vector <int> frequencies(26), counts(26);
  vector <Likelihood> likelihoods(26);
  string fileString;
  readFrequencies(&frequencies);
  readFile(argv[1], &fileString, &counts);
  setLikelihoods(frequencies, counts, &likelihoods);
  writeVersions(fileString, likelihoods);
  return 0;
} // main())

