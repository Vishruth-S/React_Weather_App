#!/usr/bin/bash
sum=0
for i in $@;
do
 if [ $i -gt 10 ]
 then
  sum=$((sum+i));
 fi
done
echo "Sum of numbers greater than 10: $sum"
