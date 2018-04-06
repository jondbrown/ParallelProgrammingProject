#ifndef RECURSIVE_H
#define RECURSIVE_H

#include <vector>
#include "tour.h"

class recursive
{
public:
	#define HOMETOWN 0
	
	recursive();
	~recursive();
	
	void PrintBestTour();

	//Find the current number of cities in the current tour
	int CityCount(Tour& tour);

	//overwrites the best tour with the current tour
	void UpdateBestTour(Tour& tour);

	//determines if a city is not included in the current tour
	bool Feasible(Tour& tour, int city);

	//adds city to current tour
	void AddCity(Tour& tour, int city);

	//removes last city in tour
	void RemoveLastCity(Tour& tour);

	//determines if current tour is better than best tour
	bool BestTour(Tour& tour);

	//main recursive function
	void DepthFirstSearch(Tour& tour);
	
private:
	Tour bestTour = Tour();
	size_t bestTourCost;
};

#endif // RECURSIVE_H
