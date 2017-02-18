#!/bin/user
read a
result=`find . -name "*$a"`
$result=$result|cut -d "." -f 2 

# for i in $result; do
# 	name=` 
# 	echo $name
# done