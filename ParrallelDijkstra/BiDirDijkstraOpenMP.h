#pragma once

#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <omp.h>

#include "Distance.h"
#include "DistanceComparator.h"
#include "Utils.h"
#include "AdjMatrix.h"

class BiDirDijkstraOpenMP
{
	static int isIntersecting(const std::vector<bool>& fVisited, const std::vector<bool>& bVisited, int verticesNumber);
public:
	static double ShortestPath(int ** graph, int source, int destination, int verticesNumber);
};