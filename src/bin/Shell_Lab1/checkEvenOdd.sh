#!/usr/bin/bash
read -p "Enter a number: " num
if [ $((num%2)) -eq 0 ]
then
  echo "Entered number is even"
else
  echo "Entered number is odd"
fi
