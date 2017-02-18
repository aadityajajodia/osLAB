#!/bin/bash
declare -a myArray
x=0
for i in $@;do
	myArray[x]=$i
	((x++))
done
for i in ${myArray[@]};do
	echo $i
done

for((i=0;i<$#-1;i++));do
	for((j=0;j<$#-i-1;j++));do
		if [ ${myArray[$j]} \> ${myArray[$((j+1))]} ]; then
			{
				temp=${myArray[$j]}
				myArray[$j]=${myArray[$((j+1))]}
				myArray[$((j+1))]=$temp
			}
		fi
	done
done
echo "the sorted list is:"
for i in ${myArray[@]};do
	echo $i
done