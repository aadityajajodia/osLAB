#/bin/bash

files=`ls *sh`

for i in $files;do
	
	
	cat $i>>combine.txt 
	cat changeLine.txt>>combine.txt

done