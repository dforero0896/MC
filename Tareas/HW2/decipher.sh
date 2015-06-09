#!/bin/bash
one=$(echo vhpuzsfgxedrmbjacyktqolwni)
two=$(echo zyxwvutsrqponmlkjihgfedcba)
letter1=$1
letter2=$2
file=$3

len=${#one}
lenf=$(($len+1))

for i in [1..10]; do
    for j in $(seq 0 $len); do
	$j
    done
    sed "s/$letter1/TEMPORARYONE/g;s/$letter2/TEMPORARYTWO/g;s/TEMPORARYONE/$letter2/g;s/TEMPORARYTWO/$letter1/g" $file

done
