#!/bin/bash


if [[ -e "bin" ]]; then
    rm bin -rf
fi

mkdir bin
g++ threads_stack.cpp -o bin/threads_stack -lpthread -pg
cd bin
./threads_stack
gprof threads_stack gmon.out > profile.txt
gprof2dot -e 0 -n 0 profile.txt -o profile.g
dot -Tsvg profile.g -o result.svg
firefox result.svg
