#!/bin/bash

for ((i=0; i < 40; i++)); do
	RAND_NUM=`./push_swap_tester/rand_num 100 1 1000`
	CMD=`./push_swap $RAND_NUM | wc -l`
#	if [ $CMD -ge 670 ]
#	then
#		echo $CMD
#	fi
	echo -n `echo $RAND_NUM | xargs ./push_swap | wc -l`
	echo -n "	"
	./push_swap $RAND_NUM | ./checker $RAND_NUM
done
