#include "TimeTest.h"

int main()
{
	unsigned int testNumber = 10;
	unsigned int verticesNumber = 100;
	unsigned int edgesNumber = 9000;
	//int** test4by4Mat = AdjMatrix::Test4by4Matrix();
	//BiDirDijkstra::ShortestPath(test4by4Mat, 1, 2, 4);
	//BiDirDijkstraOpenMP::ShortestPath(test4by4Mat, 0, 3, 4);
	for(int i = 50; i < 2000; i+=250)
	{
		unsigned int verticesNumber = i;
		unsigned int edgesNumber = verticesNumber * verticesNumber - 10;
		TimeTest timeTest = TimeTest(testNumber, verticesNumber, edgesNumber);
		timeTest.Start();
	}
	
	std::cin.get();
	return 0;
}