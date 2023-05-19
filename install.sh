#!/bin/bash
clear

mkdir sda
chmod u+x run.sh
g++ install.cpp -o install
./install
cd sda
mkdir bin
cd bin
mkdir pkgs
cd pkgs
git clone https://github.com/steiyve/the-pakage.git
cd ../../..
g++ packageManager/firstTimeRun.cpp -o firstTimeRun.o
./firstTimeRun.o
