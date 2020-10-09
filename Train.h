#ifndef TRAIN_H
#define TRAIN_H

#include <vector>
#include "Station.h"

class Train
{
private:
	int trainNumber;
	double averageSpeed;
	Station currentStation;
	int nextArrivalTime;
	std::vector<Station> route;
	int countdown;

public:
	Train(Station& currLoc, int trainNum = 0, double avgSpeed = 0, int arrivalTime = 0, std::vector<Station> newRoute = {}) :
		trainNumber{ trainNum }, averageSpeed{ avgSpeed }, currentStation{ currLoc }, nextArrivalTime{ arrivalTime }, route{ newRoute }, countdown{ -1 }
	{

	}

	void addStationToRoute(Station& newStation);
	Station getNextStation();

	void setArrivalTime(int currentTime);
	int getArrivalTime() { return nextArrivalTime; }

	void setCurrentStation(Station& newStation);
	Station getCurrentStation() { return currentStation; }

	int getTrainNumber() { return trainNumber; }

	void startCountdown() { countdown = 5; }
	int getCountdown() { return countdown; }
	void decrementCountdown() { countdown--; }

	
};

#endif // !TRAIN_H