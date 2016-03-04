#!  /bin/bash

testerDirectory="/home/ssdavis/40/p1/Testing"

if [ $# -ne 1 ]; then
  >&2 echo "usage DesignChecker.sh: $testerDirectory/DesignChecker.sh CPU.out_directory"
  exit
fi

if [[ $1 =~ Testing ]]; then # Use from this directory is not allowed
  >&2 echo "You may not use Testing as your own source directory!"
  exit
fi

cd $1

rm -f designResults.txt
designError=0
dos2unix *.c *.h &> /dev/null

grep "/\*" *.c *.h > temp
if [ -s temp ]; then
  cat temp >> designResults.txt
  echo 'Fatal design error: "\*" found.' >> designResults.txt
  ((++designError))
fi

openBracketCount=$( grep -v "//" *.h | grep "{" | wc -l )

if [ $openBracketCount -ne 5 ]; then
  echo 'Fatal design error: Implementation code found in header file.' >> designResults.txt
  ((+designError))
fi

# non-fatal designerrors from here on


grep -v "^ *//" instruction.h | awk '/typedef struct/,/}/' | grep "Instruction" > temp 
grep -v "^ *//" instruction.h | grep "class *Instruction" >> temp 
if [ ! -s temp ]; then
  echo 'Design error: No Instruction typedef struct or class in instruction.h.' >> designResults.txt
fi

grep -v "^ *//" registers.h | awk '/typedef struct/,/}/' | grep "Registers" > temp              
grep -v "^ *//" registers.h | grep "class *Registers" >> temp
if [ ! -s temp ]; then
  echo 'Design error: No Registers typedef struct or class in registers.h.' >> designResults.txt
fi

grep -v "^ *//" reader.h | awk '/typedef struct/,/}/' | grep "Reader" > temp              
grep -v "^ *//" reader.h | grep "class *Reader" >> temp
if [ ! -s temp ]; then
  echo 'Design error: No Reader typedef struct or class in reader.h.' >> designResults.txt
fi


grep -v "^ *//" decoder.h | awk '/typedef struct/,/}/' | grep "Decoder" > temp              
grep -v "^ *//" decoder.h | grep "class *Decoder" >> temp
if [ ! -s temp ]; then
  echo 'Design error: No Decoder typedef struct or class in decoder.h.' >> designResults.txt
fi

mv main.c main.c2

grep -v "^ *//" *.c | egrep "Reader[ ]+[^*]" > temp
grep -v "^ *//" *.c | egrep "Instruction[ ]+[^*]" >> temp
grep -v "^ *//" *.c | egrep "Registers[ ]+[^*]" >> temp
grep -v "^ *//" *.c | egrep "Decoder[ ]+[^*]" >> temp

if [ -s temp ]; then
  echo 'Design error: struct not passed as a pointer.' >> designResults.txt
fi

grep -v "^ *//" *.c | grep Decoder | grep -v decoder.c > temp

if [ -s temp ]; then
  echo 'Design error: Decoder used in function outside decoder.c.' >> designResults.txt
fi

grep -v "^ *//" *.c | grep Reader | grep -v Decoder | grep -v reader.c > temp

if [ -s temp ]; then
  echo 'Design error: Reader used in function outside reader.c, or a function with a Decoder.' >> designResults.txt
fi

mv main.c2 main.c

grep -v "^ *//" decoder.c | grep " addl *(" > temp

if [ ! -s temp ]; then
  echo 'Design error: No addl function in decoder.c' >> designResults.txt
fi

grep -v "^ *//" decoder.c | grep " andl *(" > temp

if [ ! -s temp ]; then
  echo 'Design error: No andl function in decoder.c' >> designResults.txt
fi

grep -v "^ *//" decoder.c | grep " leave *(" > temp

if [ ! -s temp ]; then
  echo 'Design error: No leave function in decoder.c' >> designResults.txt
fi

grep -v "^ *//" decoder.c | grep " movl *(" > temp

if [ ! -s temp ]; then
  echo 'Design error: No movl function in decoder.c' >> designResults.txt
fi

grep -v "^ *//" decoder.c | grep " pushl *(" > temp

if [ ! -s temp ]; then
  echo 'Design error: No pushl function in decoder.c' >> designResults.txt
fi

grep -v "^ *//" decoder.c | grep " ret *(" > temp

if [ ! -s temp ]; then
  echo 'Design error: No ret function in decoder.c' >> designResults.txt
fi

grep -v "^ *//" decoder.c | grep " subl *(" > temp

if [ ! -s temp ]; then
  echo 'Design error: No subl function in decoder.c' >> designResults.txt
fi

grep -v "^ *//" *.c | awk '/void/ , /\)/' | grep ";" > temp

if [ -s temp ]; then
  echo 'Design error: Prototype in *.c file.' >> designResults.txt
fi

echo $designError  # Only standard out

