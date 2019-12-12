#pragma once

#include <iostream>
#include "AdjMatrix.h"
#include "BiDirDijkstra.h"
#include "BiDirDijkstraOpenMP.h"

class TimeTest
{
	unsigned int testNumber, verticesNumber, edgesNumber;
	double sequentialTime, parallelTime;
public:
	TimeTest(unsigned int testNumber, unsigned int verticesNumber = 100, unsigned int edgesNumber = 9000);

	void Start();

	~TimeTest();
};