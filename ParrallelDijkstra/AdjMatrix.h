#pragma once

#include <iostream>
#include "Utils.h"

class AdjMatrix
{
	static int AddEdge(int edgesAdded);
public:
	static int** Init(unsigned int verticesNumber, unsigned int edgesNumber);

	static int** Transpose(int** sourceMat, unsigned int sourceVerticesNumber);

	static void PrintMat(int** mat, int verticesNumber);

	static int** Test4by4Matrix();

	static void RemoveMatrix(int** mat, unsigned int verticesNumber);
};