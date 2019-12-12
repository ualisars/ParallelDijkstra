#include "BiDirDijkstra.h"

int BiDirDijkstra::isIntersecting(std::vector<bool> fVisited, std::vector<bool> bVisited, int verticesNumber)
{
	for (int i = 0; i < verticesNumber; ++i)
	{
		if (fVisited[i] && bVisited[i])
			return i;
	}
	return std::numeric_limits<int>::max();
}

double BiDirDijkstra::ShortestPath(int** fGraph, int source, int destination, int verticesNumber)
{
	auto start = std::chrono::steady_clock::now();
	std::vector<int> fParents, bParents;
	std::vector<int> fDistance, bDistance;
	std::vector<bool> fVisited, bVisited;

	int terminationNode = std::numeric_limits<int>::max();

	fParents.resize(verticesNumber);
	bParents.resize(verticesNumber);

	fDistance.resize(verticesNumber);
	bDistance.resize(verticesNumber);

	fVisited.resize(verticesNumber);
	bVisited.resize(verticesNumber);

	int** bGraph = AdjMatrix::Transpose(fGraph, verticesNumber);

	std::priority_queue <Distance, std::vector<Distance>, DistanceComparator> fQ, bQ;

	for (int i = 0; i < verticesNumber; ++i)
	{
		fParents[i] = std::numeric_limits<int>::max();
		bParents[i] = std::numeric_limits<int>::max();
		fDistance[i] = std::numeric_limits<int>::max();
		bDistance[i] = std::numeric_limits<int>::max();
		fVisited[i] = false;
		bVisited[i] = false;
	}

	fQ.push(Distance(source, 0));
	fDistance[source] = 0;

	bQ.push(Distance(destination, 0));
	bDistance[destination] = 0;
	
	while (!fQ.empty() && !bQ.empty())
	{
		int fU = fQ.top().GetVertex();
		int bU = bQ.top().GetVertex();
		
		terminationNode = isIntersecting(fVisited, bVisited, verticesNumber);
		if (terminationNode != std::numeric_limits<int>::max())
			break;
			
		fVisited[fU] = true;
		bVisited[bU] = true;
		fQ.pop();
		bQ.pop();

		int* fAdjacency = fGraph[fU];
		int* bAdjacency = bGraph[bU];

		// relax forward search
		for (int i = 0; i < verticesNumber; ++i)
		{
			if (fAdjacency[i] == 0)
				continue;
			int newWeight = fDistance[fU] + fAdjacency[i];
			if (fDistance[i] > newWeight)
			{
				fDistance[i] = newWeight;
				fParents[i] = fU;
				fQ.push(Distance(i, newWeight));
			}
		}

		// relax backward search
		for (int i = 0; i < verticesNumber; ++i)
		{
			if (bAdjacency[i] == 0)
				continue;
			int newWeight = bDistance[bU] + bAdjacency[i];
			if (bDistance[i] > newWeight)
			{
				bDistance[i] = newWeight;
				bParents[bU] = i;
				bQ.push(Distance(i, newWeight));
			}
		}
	}

	//std::cout << "Sequencial Bi-Directional Dijkstra Algorithms" << std::endl;
	auto end = std::chrono::steady_clock::now();
	auto diff = end - start;
	//std::cout << "Sequential Dijkstra: ";

	auto time = std::chrono::duration <double, std::milli>(diff).count();
	//std::cout << time << " ms" << std::endl;

	//Utils::ConstructPath(source, destination, terminationNode, fParents, bParents);
	AdjMatrix::RemoveMatrix(bGraph, verticesNumber);

	return time;
}
