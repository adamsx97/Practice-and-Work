#!  /bin/bash

testerDirectory="/home/ssdavis/40/p5/Testing"

if [ $# -ne 1 ]; then
  >&2 echo "usage DesignChecker.sh: $testerDirectory/DesignChecker.sh CPU.out_directory"
  exit
fi

if [[ $1 =~ Testing ]]; then # Use from this directory is not allowed
  >&2 echo "You may not use Testing as your own source directory!"
  exit
fi

cd $1

rm -f designResults.txt *.o
designError=0
dos2unix *.cpp *.h &> /dev/null

grep "/\*" *.cpp *.h > temp
if [ -s temp ]; then
  cat temp >> designResults.txt
  echo 'Fatal design error: "/*" found.' >> designResults.txt
  (( ++designError ))
fi

openBracketCount=$( grep -v "//" *.h | grep "{" | wc -l )

if [ $openBracketCount -ne 10 ]; then
  echo 'Fatal design error: Implementation code found in header file.' >> designResults.txt
  (( ++designError ))
fi

if egrep "(struct |stdio|string\.h|stdlib\.h|malloc|free|print|fopen|read[^a-z])" *.h *.cpp >& /dev/null ; then
  echo 'Fatal design error: struct, stdio, string.h, stdlib.h, malloc, free,' >> designResults.txt
  echo 'print, fopen, or read found in file(s).' >> designResults.txt
  (( +designError ))
fi

grep -v "^ *//" *.cpp| awk '/void/ , /\)/' | grep ";" > temp

if [ -s temp ]; then
  echo 'Fatal design error: Prototype in *.cpp file.' >> designResults.txt
  (( ++designError ))
fi

if [[ ` grep int main.cpp  | wc -l` -ne 1 ]]; then
  echo 'Fatal design error: More than one "int" in main.cpp.'  >> designResults.txt
  (( ++ designError ))
fi

if [[ ` grep -i "reader" *.h *.cpp  | wc -l` -ne 0 ]]; then
  echo 'Fatal design error: [Rr]eader found in source code.'  >> designResults.txt
  (( ++ designError ))
fi

if [[ ` grep -v "//" word.h | grep ";" | wc -l ` -ne 4 ]]; then
  echo 'Fatal design error: Four ";" not found in word.h'  >> designResults.txt
  (( ++ designError ))
fi 

if [[ ` grep ";" data.h | wc -l ` -ne 6 ]]; then
  echo 'Fatal design error: Six ";" not found in data.h'  >> designResults.txt
  (( ++ designError ))
fi

if [[ ` awk '/ListNode *:: *~ListNode *\(/, /}/' memory.cpp | grep -v "//" | grep "delete *word" | wc -l ` -ne 1 ]]; then
  echo 'Fatal design error: ListNode destructor does not delete its word in memory.cpp'  >> designResults.txt
  (( ++ designError ))
fi

if [[ ` awk '/Memory *:: *~Memory *\(/, /}/' memory.cpp | grep -v "//" | grep "delete " | wc -l ` -ne 1 ]]; then
  echo 'Fatal design error: Memory destructor does not delete the ListNodes in memory.cpp'  >> designResults.txt
  (( ++ designError ))
fi


if [[ ` grep  "int *[a-zA-Z]* *\[" *.cpp *.h  | wc -l` -ne 1 ]]; then
  echo 'Fatal design error: int array other than regs found in source code.'  >> designResults.txt
  (( ++ designError ))
fi

if [[ `  grep address data.* instruction.* | wc -l` -ne 0 ]]; then
  echo 'Fatal design error: address found in data.* instruction.*.'  >> designResults.txt
  (( ++ designError ))
fi

# non-fatal design errors from here on



awk '/public/,/};/' decoder.h > public
awk '/class/,/public/' decoder.h > private


if ! grep "void *cmpl(" private  &> /dev/null || grep "cmpl" public  &> /dev/null ; then
  echo "cmpl( not private in decoder.h" >> designResults.txt
fi

if ! grep "void *incl(" private  &> /dev/null || grep "incl" public  &> /dev/null ; then
  echo "incl( not private in decoder.h" >> designResults.txt
fi

if ! grep "void *jg(" private  &> /dev/null || grep "jg" public  &> /dev/null ; then
  echo "jg( not private in decoder.h" >> designResults.txt
fi

if ! grep "void *jle(" private  &> /dev/null || grep "jle" public  &> /dev/null ; then
  echo "jle() not private in decoder.h" >> designResults.txt
fi

if ! grep "void *jmp(" private  &> /dev/null || grep "jmp" public  &> /dev/null ; then
  echo "jmp( not private in decoder.h" >> designResults.txt
fi

if ! grep "void *leal(" private  &> /dev/null || grep "leal" public  &> /dev/null ; then
  echo "leal( not private in decoder.h" >> designResults.txt
fi

if ! grep "void *call(" private  &> /dev/null || grep "call" public  &> /dev/null ; then
  echo "call() not private in decoder.h" >> designResults.txt
fi

if ! grep "void *sall(" private  &> /dev/null || grep "sall" public  &> /dev/null ; then
  echo "sall() not private in decoder.h" >> designResults.txt
fi

if ! grep "void *decl(" private  &> /dev/null || grep "sall" public  &> /dev/null ; then
  echo "decl() not private in decoder.h" >> designResults.txt
fi

if ! grep "void *imull(" private  &> /dev/null || grep "sall" public  &> /dev/null ; then
  echo "imull() not private in decoder.h" >> designResults.txt
fi

if ! awk '/parse/, /;/' public | grep "Labels"  &> /dev/null || grep "parse" private  &> /dev/null ; then
  echo "Labels passed in parse() not in public in decoder.h" >> designResults.txt
fi

if [[ ` grep -v "//" decoder.cpp | grep setFlags  | wc -l` -ne 8 ]]; then
  echo "setFlags not called proper number of times in decoder.cpp"  >> designResults.txt
fi

if [[ ` grep -v "//" decoder.cpp | grep += decoder.cpp | wc -l` -lt 3 ]]; then
  echo "+= not called proper number of times in decoder.cpp"  >> designResults.txt
fi

if [[ ` grep call decoder.h | grep -o const  | wc -l` -ne 1 ]]; then
  echo "Decoder::call  is not a const method"  >> designResults.txt
fi

if [[ ` grep cmpl  decoder.h | grep -o const  | wc -l` -ne 1 ]]; then
  echo "Decoder::cmpl  is not a const method"  >> designResults.txt
fi

if [[ ` grep jg  decoder.h | grep -o const  | wc -l` -ne 1 ]]; then
  echo "Decoder::jg  is not a const method"  >> designResults.txt
fi

if [[ ` grep jle  decoder.h | grep -o const  | wc -l` -ne 1 ]]; then
  echo "Decoder::jle  is not a const method"  >> designResults.txt
fi

if [[ ` grep jmp  decoder.h | grep -o const  | wc -l` -ne 1 ]]; then
  echo "Decoder::jmp  is not a const method"  >> designResults.txt
fi

if [[ ` grep leal decoder.h | grep "const *Registers"  | wc -l` -ne 1 ]]; then
  echo "Decoder::leal does not have a const Register*"  >> designResults.txt
fi

if [[ ` grep leave decoder.h | grep "const[ &]*Memory"  | wc -l` -ne 1 ]]; then
  echo "Decoder::leave does not have a const &Memory"  >> designResults.txt
fi

if [[ ` grep "ret *(" decoder.h | grep "const[ &]*Memory"  | wc -l` -ne 1 ]]; then
  echo "Decoder::ret does not have a const &Memory"  >> designResults.txt
fi


awk '/public/,/};/' registers.h > public
awk '/class/,/public/' registers.h > private

if ! grep "int regs\[8" private  &> /dev/null || grep "regs" public  &> /dev/null ; then
  echo "regs[8 not private in registers.h" >> designResults.txt
fi

if ! grep "address(.*Labels.*)" public  &> /dev/null ; then
  echo "Labels passed in address() not found in public in registers.h" >> designResults.txt
fi

if ! grep "typedef .*enum .*edx," registers.h  &> /dev/null ; then
  echo "edx enum not found in registers.h" >> designResults.txt
fi

if ! grep "typedef.*enum.*flags" registers.h  &> /dev/null ; then
  echo "flags enum not found in registers.h" >> designResults.txt
fi

if ! grep "operator *<<" registers.h  &> /dev/null ; then
  echo "operator<< not found in registers.h" >> designResults.txt
fi

if ! grep "operator *+=" registers.h  &> /dev/null ; then
  echo "operator+= not found in registers.h" >> designResults.txt
fi

if [[ ` grep address registers.h | grep -o const  | wc -l` -ne 1 ]]; then
  echo "Registers::address does not have labels as a const"  >> designResults.txt
fi

if [[ ` grep find labels.h | grep -o const  | wc -l` -ne 2 ]]; then
  echo "Labels::find does not have two consts"  >> designResults.txt
fi

if [[ ` awk '/^ *class *Labels/, /public/' labels.h | grep "Instruction2 *[a-zA-Z]* *\[" | wc -l` -ne 1 ]]; then
  echo "Labels class does not have a private Instruction2 array"  >> designResults.txt
fi

if ! awk '/^ *class *Word/,/public/' word.h | grep "int *address" &> /dev/null ; then
  echo "Word::address was not private."  >> designResults.txt
fi

if ! grep "Word *( *int *[a-z]* *)" word.h  &> /dev/null ; then
  echo "Word constructor with only an int as parameter not found." >> designResults.txt
fi

if ! grep "operator *< *(.*Word" word.h  &> /dev/null ; then
  echo "operator< not found in word.h." >> designResults.txt
fi

if ! grep "virtual *~Word" word.h  &> /dev/null ; then
  echo "virtual destructor not found in word.h." >> designResults.txt
fi


if ! grep "class *Data *: *public *Word" data.h  &> /dev/null ; then
  echo "Data class not publicly derived from Word." >> designResults.txt
fi

if ! grep "Data *( *int *[a-z]* *)" data.h  &> /dev/null ; then
  echo "Data constructor with only an int as parameter not found." >> designResults.txt
fi

if ! grep "operator *= *( *int *[a-z]* *)" data.h  &> /dev/null ; then
  echo "Assignment operator that takes an int as its only parameter not found in data.h" >> designResults.txt
fi

if [[ ` grep -v "//" data.h | grep "get *(.*) *const *;" | wc -l ` -ne 1 ]]; then
  echo "Data class does not have a const get() method."  >> designResults.txt
fi

if [[ ` grep -v "//" data.h | grep "^ *int& *get *(.*) *;"  | wc -l ` -ne 1 ]] ; then
  echo "Data class does not havea non-const get() method."  >> designResults.txt
fi

if [[ ` awk '/class *ListNode/,/};/' memory.h | grep ";" | wc -l ` -ne 6 ]]; then
  echo 'Six ";" not found in ListNode class'  >> designResults.txt
fi

if [[ ` awk '/class *Memory *([^;]|$)/,/};/' memory.h | grep ";" | wc -l ` -ne 9 ]]; then
  echo 'Nine ";" not found in Memory class'  >> designResults.txt
fi

if [[ ` grep -v "//" memory.h | grep "^ *Word& *operator *\[\] *(.*);" | wc -l ` -ne 1 ]]; then
  echo "Memory class does not have a non-const operator[] method."  >> designResults.txt
fi

if [[ ` grep -v "//" memory.h | grep "Word& *operator *\[\] *(.*) *const *;" | wc -l ` -ne 1 ]]; then
  echo "Memory class does not have a const operator[] method."  >> designResults.txt
fi


if [[ ` grep -v "//" memory.h | grep "insert *( *Word *\* *[a-z]* *) *;" | wc -l ` -ne 1 ]]; then
  echo "Memory class does not have an insert method that takes a Word* as its only parameter."  >> designResults.txt
fi

if ! grep "const *Instruction.*fetch" memory.h  &> /dev/null ; then
  echo "Memory::fetch() does not return a const." >> designResults.txt
fi

if ! grep "class *Instruction *: *public *Word" instruction.h  &> /dev/null ; then
  echo "Instruction class not publicly derived from Word." >> designResults.txt
fi

if ! grep "operator *=.*const *char" instruction.h  &> /dev/null ; then
  echo "Parameter in assignment operator in Instruction class not const." >> designResults.txt
fi

if ! grep "operator *<<.*const *Instruction" instruction.h  &> /dev/null ; then
  echo "Instruction parameter in operator<< in Instruction class not const." >> designResults.txt
fi

echo $designError  # Only standard out

