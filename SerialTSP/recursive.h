#ifndef RECURSIVE_H
#define RECURSIVE_H

#include <vector>

class recursive
{
public:
	#define NUM_CITIES 4
	#define HOMETOWN 0
	
	recursive();
	~recursive();
	
	void PrintBestTour();
	
	void PrintAdjMat();

	//Find the current number of cities in the current tour
	int CityCount(int* tour);

	//overwrites the best tour with the current tour
	void UpdateBestTour(int* tour);

	//determines if a city is not included in the current tour
	bool Feasible(int* tour, int city);

	//adds city to current tour
	void AddCity(int* tour, int city);

	//removes last city in tour
	void RemoveLastCity(int* tour, int city);

	//determines if current tour is better than best tour
	bool BestTour(int* tour);

	//main recursive function
	void DepthFirstSearch(int* tour);
	
private:
	const int adjMat[NUM_CITIES][NUM_CITIES] = {{-1,1,3,8},{4,-1,1,6},{1,18,-1,10},{7,4,12,-1}};
	int bestTour[NUM_CITIES] = {0, 1, 2, 3};
};

#endif // RECURSIVE_H
