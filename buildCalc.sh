#!/bin/bash
rm -r build
mkdir build
cd build
cmake -DBUILD_TESTS=ON ..
make

