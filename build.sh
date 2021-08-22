#! /bin/bash
DIR=$(dirname $0)
cd $DIR
gcc -std=c89 \
  $(sdl2-config --cflags) \
  $(find src -name '*.c') \
  main2.c \
  $(sdl2-config --libs) \
  -lSDL2_image \
  -o build
 
#  -lSDL2main \
