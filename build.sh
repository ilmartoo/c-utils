#!/bin/bash
# Valid values are:
#  - clean: Will erase the contents of the bin/ directory
#  - build: Will build the project
#  - run: Will run the executable (builds the project if not built already)

for arg in "$@"; do
    if [[ "${arg^^}" == "CLEAN" ]]; then
        echo "[CLEAN]"
        rm -rf bin
        mkdir bin
    elif [[ "${arg^^}" == "BUILD" ]]; then
        echo "[BUILD]"
        if [ ! -d "bin" ]; then 
            mkdir bin
        fi
        make tests
    elif [[ "${arg^^}" == "RUN" ]]; then
        echo "[RUN]"
        if [ ! -d "bin" ]; then
            mkdir bin
        fi
        make run-tests
    fi
done