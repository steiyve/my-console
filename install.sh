#!/bin/bash
clear

mkdir sda
chmod u+x run.sh
g++ install.cpp -o install
./install
cd sda
cd bin
mkdir pkgs
cd pkgs
git clone https://github.com/steiyve/the-pakage.git
cd the-pakage
chmod u+x cmatrix.sh
chmod u+x neofetch.sh
chmod u+x update_pacman.sh
chmod u+x update.sh
cd ../../../..
chmod u+x update.sh
g++ firstTimeRun.cpp -o firstTimeRun.o
./firstTimeRun.o
