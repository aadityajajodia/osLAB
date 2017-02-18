#!/bin/bash
echo "enter basics"
read basics
echo "enter TA"
read TA
result=`echo "$basics+$TA+0.1*$basics"|bc -l`
echo $result