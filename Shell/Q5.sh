#!/bin/bash
echo "enter extension"
read ext
echo "enter new folder name"
read folder
mkdir $folder
cp *$ext $folder