#!/bin/bash
one=$(echo vhpuzsfgxedrmbjacyktqolwni)
two=$(echo zyxwvutsrqponmlkjihgfedcba)
filename=$1
len=${#one}

#for i in {1..10}; do
    for j in $(seq 0 $(($len-1))); do
	letter1=${one:$j:1}
	letter2=${two:$j:1}
        
	echo $letter1 $letter2
	./flip.sh $letter1 $letter2 $filename > $j.txt
       
	filename=$(echo $j.txt)
         
#	rm $j.txt
    done
  
#done

