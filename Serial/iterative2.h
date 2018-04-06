#pragma once
#include <stack>
#include <memory>
#include <vector>
#include "Tour.h"

using namespace std;

//pushes partial tours into the stack instead of cities
class iterative2
{
public:
	iterative2();
	~iterative2();

	//STACK FUNCTIONS
	void PushCopy(Tour tour);
	bool Empty();
	Tour Pop();

	//TOUR FUNCTIONS
	void AddCity(Tour& currentTour, int city);
	int CityCount(Tour currentTour);
	bool BestTour(Tour currentTour);
	void UpdateBestTour(Tour currentTour);
	bool Feasible(Tour currentTour, int city);
	void RemoveLastCity(Tour& currentTour);
	void DepthFirstSearch(Tour currentTour);

	//PRINT FUNCTIONS
	void PrintBestTour();

private:
	Tour bestTour = Tour();
	size_t bestTourCost = SIZE_MAX;
	stack<Tour> theStack;

};

