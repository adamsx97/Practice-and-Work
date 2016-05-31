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
	printf("%d %d %d\n", this->sign, this->mantissa, this->exponent);

	return *this;
} // overloaded operator +

MyFloat operator-(const MyFloat& rhs) const{
	MyFloat temp(rhs);
	temp.sign = !temp.sign;
	return *this + temp;
} // overloaded operator -


void MyFloat::unpackFloat(float f) {

	__asm__(
		//this->sign = (i >> 31); 
		"shr $31, %%eax;"

		//this->exponent = (i << 1) >> 23;  
		"shl $1, %%ebx;"
		"shr $24, %%ebx;"

		//this->mantissa = (i << 9) >> 9;
		"shl $9, %%ecx;"
		"shr $9, %%ecx":

		"=a" (sign), "=b" (exponent), "=c" (mantissa):
		"a" (f), "b" (f), "c" (f):
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
