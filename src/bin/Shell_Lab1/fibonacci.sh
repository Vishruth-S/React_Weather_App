#!/usr/bin/bash
echo "Enter a number"
read n
a=0
b=1
echo "Fibonacci series"
echo -ne "$a $b "
while [ $n -gt 2 ]
do
  c=$(($a+$b))
  a=$b
  b=$c
  echo -ne "$c "
  n=$((n-1))
done
echo

