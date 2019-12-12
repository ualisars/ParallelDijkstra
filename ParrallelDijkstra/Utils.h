#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <random>

class Utils
{
	static std::stack<int> ConstructForwardPath(int source, int terminationNode, std::vector<int> parents);

	static std::stack<int> ConstructBackwardPath(int destination, int terminationNode, std::vector<int> bParents);

	static void TraversePath(std::stack<int> path);
public:
	static void ConstructPath
	(
		int source, 
		int destination, 
		int terminatioNode,
		std::vector<int> fParents, 
		std::vector<int> bParents
	);

	static int GenerateRandomNumber(int min = 0, int max = 1);
};