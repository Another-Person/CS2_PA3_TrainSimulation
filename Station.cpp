#include "Station.h"

void Station::addStation(Station& newStation, int distance)
{
	connectedStations.push_back(newStation);
	connectedStationsDistance.push_back(distance);
}

int Station::getDistanceToStation(Station& wantedStation)
{
	for (size_t i = 0; i < connectedStations.size(); i++)
	{
		if (connectedStations.at(i) == wantedStation)
			return connectedStationsDistance.at(i);
	}
	return 0;
}

bool operator==(const Station& station1, const Station& station2)
{
	return (station1.name == station2.name); // I know this isn't a very good equality check, but for the purposes of this sim it'll work fine.
}
