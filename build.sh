#!/bin/bash
if [[ ! -e build ]]; then
	mkdir build
fi
cd build
echo "[RUNNING CMAKE]"
cmake -DTARGET_DIR=$1 -DCMAKE_BUILD_TYPE=Debug ..
echo "[RUNNING MAKE]"
make -s -j$(( $(nproc --all) + 1 ))
