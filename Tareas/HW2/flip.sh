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
#for i in $(seq 0 $len); do
    letter=${str:$i:1}
        n=$(($i+1))
	if [ $letter == $letter1 ]; then
	  echo primer 
#sed -e "s/./$letter2/$n" $file > a.txt
       	break
	elif [ $letter==$letter2 ]; then
	    echo segundo
 #      sed -e "s/./$letter1/$n" $file > b.txt
	break
       fi
 echo 1
done
