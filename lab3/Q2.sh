#!/bin/bash
echo "enter folder name"
read folder
echo "Input the pattern"
read pattern
cd $folder
ls *$pattern*
