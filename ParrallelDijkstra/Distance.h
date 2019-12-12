#pragma once

struct Distance
{
	int vertex, distance;

public:
	Distance() {}
	Distance(int vertex, int distance) : vertex(vertex), distance(distance) {}

	int GetVertex() const
	{
		return vertex;
	}
	int GetDistance() const
	{
		return distance;
	}
};