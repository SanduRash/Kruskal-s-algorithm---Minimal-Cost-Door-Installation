# Kruskal's algorithm - Minimal Cost Door Installation

## Project Overview
This project solves a graph optimization problem for a fictional home builder. The builder has a list of potential doors that can connect different rooms in a house. Each door has an associated cost. The builder wants to install a minimal set of doors such that all rooms are reachable from one another, either directly or through other rooms, and the total cost is minimized.

The problem is modeled as an undirected, weighted graph, where:
- Nodes represent rooms.
- Edges represent potential doors with associated costs.

The solution uses Kruskal’s algorithm to construct a Minimum Spanning Tree (MST), which ensures full connectivity with the lowest total cost.
## How It Works
- The program takes one command line argument: the name of the input file containing potential doors.

- Each line in the input file contains:
```bash
<room1> <room2> <cost>
```
For example:
```bash
Bedroom Garage 110
Garage Kitchen 175
```
- The program builds a graph from the input, then computes the MST using Kruskal’s algorithm with union-find data structure for cycle detection.
- The output is a single integer, the total cost of the MST (i.e., the cheapest way to connect all rooms).

## Input Example
Given house.txt with:
```bash
Bedroom Garage 110
Garage Kitchen 175
Kitchen Bedroom 200
Kitchen Office 90
Laundry Bedroom 35
Library Kitchen 25
Library Office 100
Office Game 30
Office Laundry 70
Office Bedroom 90
```
Run the program:
```bash
g++ -std=c++17 -o main mainPj4.cpp
./main house.txt
```
Expected output:
```bash
360
```

## Notes on Performance
- The implementation must run in O(m log m) time, where m is the number of potential doors (edges), using efficient sorting and union-find structures.
- The program handles up to 1,000,000 doors as specified.
