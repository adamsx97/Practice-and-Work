#! /bin/bash

testerDirectory="/home/ssdavis/40/p6/Testing"

if [ $# -ne 1 ]; then
  echo "usage Tester.sh: $testerDirectory/Tester.sh FileFind.out_directory" 1>&2
  exit
fi

if [[ $1 =~ Testing ]]; then # Use from this directory is not allowed
  echo "You may not use Testing as your own source directory!"  1>&2
  exit
fi

if [[ ! -e $1/FileFind.out ]]; then # FileFind.out not found
  echo "FileFind.out not found in $1!"  1>&2
  exit
fi

cd $1

fileNum=1
opScore=0
echo Operation testing:  1>&2

while [[ $fileNum -lt 4 ]]; do
  echo $fileNum  1>&2
  echo "File#: $fileNum" >> operationsResults.txt
  rm -f out$fileNum.txt  
  (FileFind.out $testerDirectory/File$fileNum.txt < $testerDirectory/in$fileNum.txt | head -100 > out$fileNum.txt )&
  sleep 2
  pkill FileFind.out &> /dev/null
  if [[ -s out$fileNum.txt ]]; then
    diff out$fileNum.txt $testerDirectory/out$fileNum.txt > temp

    if [ -s temp ] ; then
      echo "Not OK" >> operationsResults.txt
      echo "Yours:" >> operationsResults.txt
      cat out$fileNum.txt >> operationsResults.txt
      echo -e "\n\nSean's:" >> operationsResults.txt
      cat  $testerDirectory/out$fileNum.txt >> operationsResults.txt
    else
      echo "OK" >> operationsResults.txt
      (( opScore += 8 ))
    fi
  else
    echo "No output created so zero for operation." >> operationsResults.txt
  fi

  fileNum=$((fileNum + 1))
done  # while less than 2 for now

rm core  &> /dev/null
echo $opScore   # this is the only line that goes to stdout

