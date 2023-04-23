#!/bin/bash
sudo rm -r sda
mkdir sda
g++ install.cpp -o install
./install
