#include "TimeTest.h"

TimeTest::TimeTest(
	unsigned int testNumber, 
	unsigned int verticesNumber, 
	unsigned int edgesNumber
): testNumber(testNumber), verticesNumber(verticesNumber), edgesNumber(edgesNumber) 
{
	sequentialTime = 0.0;
	parallelTime = 0.0;
}

void TimeTest::Start()
{
	for (int i = 0; i < testNumber; ++i)
	{
		int** mat = AdjMatrix::Init(verticesNumber, edgesNumber);

		double sTime = BiDirDijkstra::ShortestPath(mat, 0, 7, verticesNumber);
		double pTime= BiDirDijkstraOpenMP::ShortestPath(mat, 0, 7, verticesNumber);

		sequentialTime += sTime;
		parallelTime += pTime;
		AdjMatrix::RemoveMatrix(mat, verticesNumber);
	}
}

TimeTest::~TimeTest()
{
	std::cout << "Time Test for Bi-Directional Dijkstra finished successfully" << std::endl;
	std::cout << testNumber << " tests were completed" << std::endl;
	std::cout << "vertices: " << verticesNumber << " edges: " << edgesNumber << std::endl;
	std::cout << "Sequential Dijkstra Time: " << sequentialTime / testNumber << " ms" << std::endl;
	std::cout << "Parallel Dijkstra Time: " << parallelTime / testNumber << " ms" << std::endl;
}
