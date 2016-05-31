#include "MyFloat.h"
#include <cstdio>

MyFloat::MyFloat(){
  sign = 0;
  exponent = 0;
  mantissa = 0;
}

MyFloat::MyFloat(float f){
  unpackFloat(f);
}

MyFloat::MyFloat(const MyFloat & rhs){
	sign = rhs.sign;
	exponent = rhs.exponent;
	mantissa = rhs.mantissa;
}

ostream& operator<<(std::ostream &strm, const MyFloat &f){
	strm << f.packFloat();
	return strm;

}

bool MyFloat::operator==(const float rhs) const{
  MyFloat temp = (MyFloat) rhs;
  if((this->sign == temp.sign) && (this->exponent == temp.exponent) && (this->mantissa == temp.mantissa))
    return true;
  else return false;
}


MyFloat MyFloat::operator+(const MyFloat& rhs) const{
	MyFloat small, big;
  int expDiff = 0, flag = 0;
	
  if (this->exponent == 0)
    return rhs;
  if (rhs.exponent == 0)
    return *this;
  if (this->sign != rhs.sign && this->mantissa == rhs.mantissa && this->exponent == rhs.exponent)
    return MyFloat(0);

  expDiff = this->exponent - rhs.exponent;
  if (this->exponent < rhs.exponent)
    {
        small = MyFloat(*this);
        big = MyFloat(rhs);
    }
  else
    {
        small = MyFloat(rhs);
        big = MyFloat(*this);
    }

  small.mantissa |= (1 << 23);
  big.mantissa |= (1 << 23);

  if (expDiff)
  {
    if  (((small.mantissa >> (expDiff - 1)) & 1) && (big.sign != small.sign))
    {
      small.mantissa >>= expDiff;
      flag = small.mantissa & 1;
      small.mantissa += 1;
    }
    else
    {
      small.mantissa >>= expDiff;  
      flag = small.mantissa & 1;
    }
  }

  small.exponent = big.exponent;

  if (small.sign == big.sign)
  {
    big.mantissa += small.mantissa;
    if (big.mantissa & (1 << 24))
    {
      big.mantissa >>= 1;
      big.exponent++;
    }
    big.mantissa &= (1 << 23) - 1;
  }
  else
  {
    if (big.mantissa < small.mantissa)
    {
      big.mantissa = small.mantissa - big.mantissa;
      big.sign = small.sign;
    }
    else
      big.mantissa = big.mantissa - small.mantissa;

    if (big.mantissa == 0)
    {
      big.sign = 0;
      big.exponent = 0;
    }
    else
    {
      int i;
      while(!(big.mantissa & (1 << 23)))
      {
        i++;
        big.mantissa <<= 1;
      }
      big.mantissa &= (1 << 23) - 1;
      big.exponent -= i;
    }
  }

	return big;
} // overloaded operator +

MyFloat MyFloat::operator-(const MyFloat& rhs) const{
	MyFloat temp = MyFloat(rhs);
	temp.sign = !temp.sign;
	return *this + temp;
} // overloaded operator -


void MyFloat::unpackFloat(float f) {

  __asm__(
    //this->sign = (i >> 31); 
    "shr $31, %%eax;"

    //this->exponent = (i >> 23) & 0xFF;  
    "shr $23, %%ebx;"
    "and $0xFF, %%ebx;"

    //this->mantissa = i & ((1 << 23) -1);
    "movl $1, %%edi;"
    "shl $23, %%edi;"
    "subl $1, %%edi;"
    "and %%edi, %%ecx":

    "=a" (sign), "=b" (exponent), "=c" (mantissa): // output
    "a" (f), "b" (f), "c" (f): // input
    "cc"
  );

}//unpackFloat



float MyFloat::packFloat() const{
  //returns the floating point number represented by this
  float f = 0;
  
  __asm__ (
  	"movl $0, %%eax;"

  	//this->sign << 31; 
  	"shl $31, %%ebx;"

  	//this->exponent << 23; 
  	"shl $23, %%ecx;"

    //sign << 31 + exponent << 23 + mantissa
    "addl %%ebx, %%eax;"
    "addl %%ecx, %%eax;"
    "addl %%edx, %%eax;"

  	:
  	"=a" (f):
  	"a" (f), "b" (sign), "c" (exponent), "d" (mantissa):
  	"cc"
  	);

  return f;
}//packFloat
//
