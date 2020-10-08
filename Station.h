#ifndef STATION_H
#define STATION_H

#include <string>
#include <vector>

class Station
{
public:

private:

	std::string name;
	std::vector<Station> connectedStations;
	std::vector<int> connectedStationsDistance;

public:
	Station(std::string name = "Station", std::vector<Station> connectedStations = {}, std::vector<int> connectedStationsDistance = {}) : 
		name{ name }, connectedStations{ connectedStations }, connectedStationsDistance{ connectedStationsDistance }
	{
		
	}
	
	void addStation(Station& newStation, int distance);

	int getDistanceToStation(Station& wantedStation);

	std::string getStationName() { return name; }

	friend bool operator==(const Station& station1, const Station& station2);

};

#endif // !STATION_H