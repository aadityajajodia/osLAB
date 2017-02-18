#!/bin/bash
echo "enter folder" # i am reading folder
read folder 	#because this current folder contains this file
cd $folder				#which contains ex and example
files=`ls -f`
for i in $files;do
	if [[ -f $i ]]; then
		sed -i -e 's/^ex/example/' $i
		sed -i -e 's/.ex/example/' $i
	fi
done