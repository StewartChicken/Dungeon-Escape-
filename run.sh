#!/bin/bash
#Run this in terminal
#+ Command to compile c++ program. here i used common one
g++ -g -std=c++17 -o compile GameDriver.cpp GamePrompts.cpp game.cpp Merchant.cpp Monster.cpp Party.cpp Map.cpp 
exit 0

