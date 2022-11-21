#!/bin/bash

make clean # empty old test cases
make all # confirm that binaries are present
mkdir testcases # Keep the test results

processes_amount=( 2 4 8 )

for i in "${processes_amount[@]}"
do
    ./chain $i > "testcases/chain_$i.txt"
    ./tree $i > "testcases/tree_$i.txt"
done
