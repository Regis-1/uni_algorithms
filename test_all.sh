#!/bin/bash

declare -a asizes=(10000 50000 100000 500000 1000000)
declare -a algorithms=("quick" "merge" "intro")
declare -a percentages=(0 25 50 75 95 99 99.7 -1)
ntests=100

for i in "${algorithms[@]}"
do
	for j in "${asizes[@]}"
	do
		for k in "${percentages[@]}"
		do
			./s0rt_my_life $j $ntests $k $i -s
			mv results.txt results-$j-$i-$k.txt
		done
	done
done

mkdir results
mv *.txt results
