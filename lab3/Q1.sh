#!/bin/bash
read a
result=`ls -l $a | cut -c 1`
echo $result
if [ "$result" = "-" ]; then
	echo "file"
else
	echo "directory"
fi