#!/bin/bash
one=$(echo vhpuzsfgxedrmbjacyktqolwni)
two=$(echo zyxwvutsrqponmlkjihgfedcba)
file=$1
len=${#one}

for i in {1..10}; do
    for j in $(seq 0 $len); do
	letter1=${one:$j:1}
	letter2=${two:$j:1}
        
	echo $letter1 $letter2
	text=$(./flip.sh $letter1 $letter2 $file)
	#file=$(echo $text)
	echo $text
       
	
    done
  
done

