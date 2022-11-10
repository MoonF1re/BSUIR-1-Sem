#!/bin/bash
SZ=20;
echo $1
if ! [ -d $1 ]; then 
  echo 'Netu Papki'
  sleep 5
  exit
else 
  echo 'Papka esty'
  cd $1
  ls -S | tail -n2 > FilesForBash.txt
  Name=$(cat FilesForBash.txt | tail -n1)
  echo 'Udalyu this'
  echo $Name "<-----"
  Size=$(stat -c %s "$Name")
  echo 'Size ='
  echo $Size
  if (("$Size" < "$SZ"));then
    rm "$Name"
  fi
  rm FilesForBash.txt
fi