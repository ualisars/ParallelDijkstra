#pragma once

#include "Distance.h"

class DistanceComparator
{
public:
	int operator() (const Distance& d1, const Distance& d2)
	{
		return d1.GetDistance() < d2.GetDistance();
	}
};