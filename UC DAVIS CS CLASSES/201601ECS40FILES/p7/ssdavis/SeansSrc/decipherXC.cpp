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

void readWords(string *wordsString)
{
  ifstream inf("words");
  stringstream strStream;
  strStream << inf.rdbuf();  //read the file
  *wordsString = strStream.str();  //str holds the content of the file
} // readWords()

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



void writeValidEnglishVersions(const string &fileString,
                               const vector <Likelihood> &likelihoods,
                               const string &wordsString,
                               int pos)
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
}  // writeValidEnglishVersions()


void writeVersions(const string &fileString, 
                   const vector <Likelihood> &likelihoods,
                   const string &wordsString)
{
  string word;
  bool OK;
  
  for(int pos = 0; pos < 26; pos++)
  {
    word = "\n";
    OK = true;
    
    for(string::const_iterator sitr = fileString.begin(); 
      sitr != fileString.end(); sitr++)
    {
      if(islower(*sitr))
        word += (*sitr - 'a' - likelihoods.at(pos).shift + 26) % 26 + 'a';
      else  // not lowercase letter
        if(isupper(*sitr))
          word +=  tolower(((*sitr - 'A' - likelihoods.at(pos).shift + 26) % 26 
            + 'A'));
        else // not letter
        {
          if(word.size() > 1)
          {
            word += '\n';
            
            if(wordsString.find(word) == string::npos)   
              OK = false;
          } // if not empty word
            
          word = "\n";
        } // else not a letter
    } // for each char in string

    if(OK)
      writeValidEnglishVersions(fileString, likelihoods, wordsString, pos);
  } // for each version 
}  // writeVersions()


int main(int argc, char** argv) 
{
  vector <int> frequencies(26), counts(26);
  vector <Likelihood> likelihoods(26);
  string fileString, wordsString;
  readFrequencies(&frequencies);
  readFile(argv[1], &fileString, &counts);
  setLikelihoods(frequencies, counts, &likelihoods);
  readWords(&wordsString);
  writeVersions(fileString, likelihoods, wordsString);
  return 0;
} // main())

