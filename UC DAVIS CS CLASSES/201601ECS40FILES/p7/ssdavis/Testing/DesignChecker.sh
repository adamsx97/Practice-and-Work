#!  /bin/bash

testerDirectory="/home/ssdavis/40/p7/Testing"

if [ $# -ne 2 ]; then
  >&2 echo "usage DesignChecker.sh: $testerDirectory/DesignChecker.sh decipher_directory operation_score"
  exit
fi

if [[ $1 =~ Testing ]]; then # Use from this directory is not allowed
  >&2 echo "You may not use Testing as your own source directory!"
  exit
fi

cd $1

rm -f designResults.txt *.o
designError=0
dos2unix decipher.cpp &> /dev/null

grep "/\*" decipher.cpp > temp
if [ -s temp ]; then
  cat temp >> designResults.txt
  echo 'Fatal design error: "/*" found.' >> designResults.txt
  (( ++designError ))
fi

if egrep "(struct |stdio|string\.h|stdlib\.h|malloc|free|fopen)" decipher.cpp >& /dev/null ; then
  echo 'Fatal design error: struct, stdio, string.h, stdlib.h, malloc, free,' >> designResults.txt
  echo 'or fopen found in file(s).' >> designResults.txt
  (( +designError ))
fi

if [[ ` grep "^ *string[^a-z]" decipher.cpp | wc -l ` -ne 1 ]] && [[ $2 -lt 29 ]] ; then
  echo 'Fatal design error: More than one string found, and not successful extra credit'  >> designResults.txt
  (( ++ designError ))
fi 

if [[ ` grep "^ *string[^a-z]" decipher.cpp | wc -l ` -gt 3 ]] ; then
  echo 'Fatal design error: More than three strings found. '  >> designResults.txt
  (( ++ designError ))
fi 
if [[ ` grep " \[" decipher.cpp | wc -l ` -gt 2 ]]; then
  echo 'Fatal design error: more than two "[" found.'  >> designResults.txt
  (( ++ designError ))
fi

if grep "c_str" decipher.cpp ; then
  echo 'Fatal design error: "c_str" found.'  >> designResults.txt
  (( ++ designError ))
fi

# non-fatal design errors from here on

if ! grep "stringstream" decipher.cpp  &> /dev/null ; then
  echo "stringstream not found." >> designResults.txt
fi

echo $designError  # Only standard out

