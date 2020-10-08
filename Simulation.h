#ifndef SIMULATION_H
#define SIMULATION_H

#include <vector>
#include "Train.h"
#include "Station.h"

class Simulation
{
private:
	int currentTime;
	std::vector<Train> trainList;
	std::vector<Station> stationList;

public:
	Simulation(int time = 0, std::vector<Train> trains = {}, std::vector<Station> stations = {}) : 
		currentTime{ time }, trainList{ trains }, stationList{ stations }
	{

	}

	void initSim();

	void run();
};

#endif // !SIMULATION_H