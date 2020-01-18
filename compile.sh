#!/bin/bash

gcc --std=c99 -Wall src/main.c -lm $(pkg-config --cflags --libs raylib) -obootz

echo compilation complete
