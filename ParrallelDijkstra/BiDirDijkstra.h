#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <chrono>
#include "Distance.h"
#include "DistanceComparator.h"
#include "Utils.h"
#include "AdjMatrix.h"

class BiDirDijkstra
{
	static int isIntersecting(std::vector<bool> fVisited, std::vector<bool> bVisited, int verticesNumber);
public:
	static double ShortestPath(int ** graph, int source, int destination, int verticesNumber);
};