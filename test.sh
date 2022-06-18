#!/bin/bash

for ((i=0; i < 100; i++)); do
	./push_swap_tester/rand_num 500 1 1000| xargs ./push_swap | wc -l
done
