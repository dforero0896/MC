#!/bin/bash
letter1=$1
letter2=$2
file=$3

sed -E 's/$letter1/$letter2/g' $file > temporal.txt
