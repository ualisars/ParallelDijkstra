#include "Utils.h"

std::stack<int> Utils::ConstructForwardPath(int source, int terminationNode, std::vector<int> parents)
{
	std::stack<int> path;
	int currentNode = terminationNode;
	path.push(currentNode);
	while (parents[currentNode] != std::numeric_limits<int>::max())
	{
		currentNode = parents[currentNode];
		path.push(currentNode);
	}
	return path;
}

std::stack<int> Utils::ConstructBackwardPath(int destination, int terminationNode, std::vector<int> bParents)
{
	std::stack<int> path;
	int currentNode = destination;
	path.push(destination);
	while (bParents[currentNode] != std::numeric_limits<int>::max())
	{
		currentNode = bParents[currentNode];
		path.push(currentNode);
	}
	return path;
}

void Utils::TraversePath(std::stack<int> path)
{
	while (!path.empty())
	{
		int node = path.top();
		std::cout << node;
		path.pop();
		if (!path.empty())
			std::cout << " -> ";
	}
}

void Utils::ConstructPath
(
	int source, 
	int destination, 
	int terminationNode, 
	std::vector<int> fParents, 
	std::vector<int> bParents
)
{
	if (terminationNode == std::numeric_limits<int>::max())
	{
		std::cout << "There is no path from node " << source << " to node " << destination << std::endl;
		return;
	}
		
	std::stack<int> fPath = ConstructForwardPath(source, terminationNode, fParents);
	std::stack<int> bPath = ConstructBackwardPath(destination, terminationNode, bParents);
	
	std::cout << "Path from node " << source << " to " << destination << " is " << std::endl;
	TraversePath(fPath);
	std::cout << " -> ";
	TraversePath(bPath);
	std::cout << std::endl;
}

int Utils::GenerateRandomNumber(int min, int max)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> dis(min, max);
	return dis(gen);
}
