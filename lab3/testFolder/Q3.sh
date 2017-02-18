#!/bin/bash
echo "enter folder name"
read folder
echo "Input the pattern"
read pattern
cd $folder
result=`find *$pattern` 
for i in 2
do
	echo $result
	part=`echo $result | cut -d " " -f 1`
	echo $part
	name=`echo $part | cut -d "." -f 1`
	echo $name	
	mv $part $name.text
done
