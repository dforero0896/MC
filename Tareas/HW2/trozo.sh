#!/bin/bash
inicio=$1
final=$2
long=$(($final - $inicio + 1))
filename=$3
text=$(cat $filename)
in=$(($inicio-1))
echo ${text:$in:$long}
