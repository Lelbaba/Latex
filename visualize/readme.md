# Visualizing bfs on a graph through a pdf. 
The scripts are written for Linux, but can be used easily in any platform as long as g++ and Lualatex is installed.

## Prerequisites
- Lualatex
- Tikz

## How to Use
- In graph.txt, input the graph you want to visualize, in the following format 
    - the first will contain three space-separated integers, number of nodes, number of edges, and the starting nodes
    - the next m lines will contain two space-sepated integers describing each edge
- Run bfs.sh
- Open result.pdf with your pdfviewer
