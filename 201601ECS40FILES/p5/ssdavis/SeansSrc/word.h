#ifndef WORD_H
#define	WORD_H

class Word 
{
  int address;
public:
  Word(int addr);
  virtual ~Word();
// int getAddress();
  bool operator< (const Word &rhs) const;
}; // class Word 



#endif	// WORD_H

