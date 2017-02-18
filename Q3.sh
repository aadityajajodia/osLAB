#!/bin/bash
read a
result=`find . -name "*$a"`
$result=$result|cut -d "." -f 2 
