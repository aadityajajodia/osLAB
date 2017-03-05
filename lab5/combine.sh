#/bin/bash

files=`ls *.c`

for i in $files;do
	
	
	cat $i>>combine.docx
	

done