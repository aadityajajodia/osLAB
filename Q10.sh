#!/bin/bash
echo "1. line count"
echo "2. word count"
echo "3. char count"
read opt
case $opt in 
	1) echo "you selected one" 
		result=`wc -l $1`
		echo $result;; 
	2) echo "you selected two"
		result=`wc -w $1`
		echo $result;;
	3) echo "you selected three"
		result=`wc -c $1`
		echo $result;;
	*) echo "you selected invalid option";;
esac