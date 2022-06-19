#!/bin/bash

for ((i=0; i < 40; i++)); do
	RAND_NUM=`./push_swap_tester/rand_num 100 1 1000`
	echo -n `./push_swap $RAND_NUM | wc -l`
	echo -n "	"
	./push_swap $RAND_NUM | ./checker $RAND_NUM
done
