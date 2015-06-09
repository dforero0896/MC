#!/bin/bash
letter1=$1
letter2=$2
file=$3
str=$(cat $file)
len=${#str}
lenf=$(($len+1))
echo $len
echo $letter1
echo $letter2

sed "s/$letter1/TEMPORARYONE/g;s/$letter2/TEMPORARYTWO/g;s/TEMPORARYONE/$letter2/g;s/TEMPORARYTWO/$letter1/g" $file

