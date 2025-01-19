#!/bin/bash
# Valid values are:
#  - clean: Will erase the contents of the bin/ directory
#  - build: Will build the project
#  - run: Will run the executable (builds the project if not built already)

for arg in "$@"; do
    if [[ "${arg^^}" == "CLEAN" ]]; then
        echo "[CLEAN]"
        make clean
    elif [[ "${arg^^}" == "BUILD" ]]; then
        echo "[BUILD]"
        make build
    elif [[ "${arg^^}" == "RUN" ]]; then
        echo "[RUN]"
        make run
    fi
done