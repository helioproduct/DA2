#!/usr/bin/env bash
source=./src/main.cpp
bin=${source%.*}

if ! g++ -std=c++11 ${source} -o ${bin}; then
    echo "ERROR: Failed to compile file."
    exit 1
fi

# mkdir -p test_big
# if ! python3 test_big.py 10 ; then
#     echo "ERROR: Failed to python generate tests."
#     exit 1
# fi

for test_file in `ls ./test_big/*.txt`; do
    ./${bin} < $test_file >> last_answer
done