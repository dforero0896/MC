#!/bin/bash
inicio=$1
final=$2
long=$(($final - $inicio + 1))
filename=$3
text=$(cat $filename)
echo ${text:$inicio-1:$long}
