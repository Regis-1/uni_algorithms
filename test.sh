#!/bin/bash

echo "Arrays size: "
read asize
echo "Number of tests: "
read ntests
echo "Percentage: "
read percentage

./s0rt_my_life $asize $ntests $percentage quick -s
mv results.txt results${asize}quick${percentage}.txt

./s0rt_my_life $asize $ntests $percentage merge -s
mv results.txt results${asize}merge${percentage}.txt

./s0rt_my_life $asize $ntests $percentage intro -s
mv results.txt results${asize}intro${percentage}.txt
