#include "Simulation.h"

#include <vector>
#include <string>
#include <iostream>
#include <limits>
#include "Train.h"
#include "Station.h"

void Simulation::initSim()
{
	// Add stations to the stationList and link them together with distances
	stationList.push_back(Station("A"));
	stationList.push_back(Station("B"));
	stationList.push_back(Station("C"));
	stationList.push_back(Station("D"));
	stationList.push_back(Station("E"));

	stationList.at(0).addStation(stationList.at(1), 10);
	stationList.at(0).addStation(stationList.at(2), 33);
	stationList.at(0).addStation(stationList.at(3), 25);
	stationList.at(0).addStation(stationList.at(4), 80);

	stationList.at(1).addStation(stationList.at(0), 10);
	stationList.at(1).addStation(stationList.at(2), 15);
	stationList.at(1).addStation(stationList.at(3), 20);

	stationList.at(2).addStation(stationList.at(0), 33);
	stationList.at(2).addStation(stationList.at(1), 15);
	stationList.at(2).addStation(stationList.at(3), 20);

	stationList.at(3).addStation(stationList.at(0), 25);
	stationList.at(3).addStation(stationList.at(1), 20);
	stationList.at(3).addStation(stationList.at(2), 20);
	stationList.at(3).addStation(stationList.at(4), 30);

	stationList.at(4).addStation(stationList.at(0), 80);
	stationList.at(4).addStation(stationList.at(3), 30);

	//Add trains to list, create routes, and set arrival times
	trainList.push_back(Train(stationList.at(0), 1, 0.166667));
	trainList.push_back(Train(stationList.at(0), 2, 0.333333));
	trainList.push_back(Train(stationList.at(3), 3, 0.083333));
	trainList.push_back(Train(stationList.at(2), 4, 0.25));

	trainList.at(0).addStationToRoute(stationList.at(0));
	trainList.at(0).addStationToRoute(stationList.at(1));
	trainList.at(0).addStationToRoute(stationList.at(2));
	trainList.at(0).addStationToRoute(stationList.at(3));
	trainList.at(0).addStationToRoute(stationList.at(4));
	trainList.at(0).addStationToRoute(stationList.at(3));
	trainList.at(0).addStationToRoute(stationList.at(2));
	trainList.at(0).addStationToRoute(stationList.at(1));

	trainList.at(1).addStationToRoute(stationList.at(0));
	trainList.at(1).addStationToRoute(stationList.at(4));

	trainList.at(2).addStationToRoute(stationList.at(3));
	trainList.at(2).addStationToRoute(stationList.at(2));
	trainList.at(2).addStationToRoute(stationList.at(1));

	trainList.at(3).addStationToRoute(stationList.at(2));
	trainList.at(3).addStationToRoute(stationList.at(0));
	trainList.at(3).addStationToRoute(stationList.at(3));

	trainList.at(0).setArrivalTime(0);
	trainList.at(1).setArrivalTime(0);
	trainList.at(2).setArrivalTime(0);
	trainList.at(3).setArrivalTime(0);

}

void Simulation::run()
{
	initSim();

	while (true)
	{
		for (size_t i = 0; i < trainList.size(); i++)
		{
			Train* currentTrain = &trainList.at(i);
			if ((*currentTrain).getArrivalTime() == currentTime)
			{
				std::cout << "Train #" << (*currentTrain).getTrainNumber() << " has arrived at station " << (*currentTrain).getNextStation().getStationName() << " at time " << currentTime << ".\n";
				std::cout << "Press enter to continue. ";
				std::cin.get();
				
				(*currentTrain).startCountdown();
				Station newTrain = (*currentTrain).getNextStation();
				(*currentTrain).setCurrentStation(newTrain);
			}
		}
		for (size_t i = 0; i < trainList.size(); i++)
		{
			Train* currentTrain = &trainList.at(i);
			if (trainList.at(i).getCountdown() <= 5 && trainList.at(i).getCountdown() > 0)
					trainList.at(i).decrementCountdown();
			else if ((*currentTrain).getCountdown() == 0)
			{
				(*currentTrain).decrementCountdown();
				std::cout << "Train #" << (*currentTrain).getTrainNumber() << " is departing station " << (*currentTrain).getCurrentStation().getStationName() << " at time " << currentTime << ".\n";
				std::cout << "Press enter to continue. ";
				std::cin.get();
				(*currentTrain).setArrivalTime(currentTime);
			}
		}

		currentTime++;
	}


}
