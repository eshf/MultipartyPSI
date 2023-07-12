#!/bin/bash

set -e

echo "building Mircal"
cd miracl/miracl/source/
sudo bash ./linux64
cd ../../..
cd miracl/miracl_osmt/source/
sudo bash ./linux64_cpp
