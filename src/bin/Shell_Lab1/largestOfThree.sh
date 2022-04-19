#!/usr/bin/bash
echo "Enter the first number"
read n1
echo "Enter the second number"
read n2
echo "Enter the third number"
read n3

if [ $n1 -gt  $n2 -a $n1 -gt $n3 ]
then
  echo "Largest is $n1"
elif [ $n2 -gt $n3 ]
then
  echo "Largest is $n2"
else
  echo "Largest is $n3"
fi
