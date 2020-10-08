#ifndef TRAIN_H
#define TRAIN_H

#include <vector>
#include "Station.h"

class Train
{
private:
	int trainNumber;
	int averageSpeed;
	Station currentStation;
	int nextArrivalTime;
	std::vector<Station> route;

public:
	Train(Station& currLoc, int trainNum = 0, int avgSpeed = 0, int arrivalTime = 0, std::vector<Station> newRoute = {}) :
		trainNumber{ trainNum }, averageSpeed{ avgSpeed }, currentStation{ currLoc }, nextArrivalTime{ arrivalTime }, route{ newRoute }
	{

	}

	void addStationToRoute(Station& newStation);
	Station getNextStation();

	void setArrivalTime();
	int getArrivalTime() { return nextArrivalTime; }

	void setCurrentStation(Station& newStation);
	Station getCurrentStation() { return currentStation; }


	
};

#endif // !TRAIN_H