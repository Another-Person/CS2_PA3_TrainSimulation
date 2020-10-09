#include <cmath>
#include "Train.h"

void Train::addStationToRoute(Station& newStation)
{
	route.push_back(newStation);
}

Station Train::getNextStation()
{
	for (size_t i = 0; i < route.size(); i++)
	{
		if (currentStation == route.at(i))
		{
			if (i == (route.size() - 1))
			{
				return route.at(0);
			}
			else
			{
				return route.at(i + 1);
			}
		}

	}
}

void Train::setArrivalTime(int currentTime)
{
	int distance = 0;
	for (size_t i = 0; i < route.size(); i++)
	{
		if (currentStation == route.at(i))
		{
			if (i == (route.size() - 1))
			{
				distance = route.at(i).getDistanceToStation(route.at(0));
			}
			else
			{
				distance = route.at(i).getDistanceToStation(route.at(i+1));
			}
		}
			
	}
	double travelTime = static_cast<double>(distance) / averageSpeed;
	int roundedTravelTime = std::floor(travelTime);
	if (roundedTravelTime != travelTime)
	{
		roundedTravelTime++; // Round up travel time to the nearest minute if it isn't a whole number already
	}
	nextArrivalTime =  roundedTravelTime + currentTime;
}

void Train::setCurrentStation(Station& newStation)
{
	currentStation = newStation;
}
