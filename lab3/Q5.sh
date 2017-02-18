#!/bin/bash
echo "enter extension"
read extension
echo "enter new folder name"
read folder
mkdir $folder
cp *$example $folder