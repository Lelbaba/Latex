#!/bin/sh
g++ bfs.cpp -o bfs.out
./bfs.out < graph.txt > gen.tex
lualatex result.tex
zathura result.pdf
