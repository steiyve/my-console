#!/bin/bash
clear
sudo rm -r sda
mkdir sda
chmod u+x run.sh
g++ install.cpp -o install
./install
