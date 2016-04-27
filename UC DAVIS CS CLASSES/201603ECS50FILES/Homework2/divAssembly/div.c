#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
  unsigned int divident, divisor, quotient, remaind, buf;
  divident = atoi(argv[1]);
  divisor = atoi(argv[2]);
  buf = divident;
  if (buf < divisor)
  {
    quotient = 0;
    remaind = buf;
  }

  else if (buf == divisor)
  {
    quotient = 1;
    remaind = 0;
  }

  else
  {
    quotient = 0;
    remaind = 0;

    for (int i = 0; i < 32; ++i)
    {
     quotient <<= 1;
     remaind <<= 1;

      if ((buf & 0x80000000) != 0)
        remaind++;
     if (remaind >= divisor)
     {
        remaind -= divisor;
        quotient++;
      }
        buf <<= 1;
    }
  }
  printf("%u / %u = %u R %u \n", divident, divisor, quotient, remaind);
  return 0;
} /* main() */