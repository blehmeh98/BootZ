#!/bin/bash

gcc --std=c99 -Wall -Iinclude/ -Llib/ src/main.c -lraylib -lm -oBootz

echo compilation complete
