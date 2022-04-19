#!/usr/bin/bash
echo "Enter a number"
read n
fact=1
while [ $n -gt 0 ]
do
  fact=$((fact * n))
  n=$((n - 1))
done
echo "Factorial is $fact"
