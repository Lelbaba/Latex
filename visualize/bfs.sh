#!/bin/sh
./bfs.out < graph.txt > gen.tex
lualatex result.tex
zathura result.pdf
