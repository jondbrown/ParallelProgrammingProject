#ifndef ITERATIVE1_H
#define ITERATIVE1_H
#include <stack>
#include "tour.h"

using namespace std;

class iterative1
{
public:
	iterative1();
	~iterative1();
	
	//STACK FUNCTIONS
	bool Empty();
	void Push(int city);
	int Pop();
	
	//TOUR FUNCTIONS
	int CityCount(Tour tour);
	
	void RemoveLastCity(Tour& tour);
	
	void AddCity(Tour& tour, int city);
	
	bool BestTour(Tour tour);
	
	void UpdateBestTour(Tour tour);
	
	bool Feasible(Tour tour, int city);
	
	void DepthFirstSearch(Tour& tour);
	
	//PRINT FUNCTIONS
	void PrintBestTour();
	
private:
	Tour bestTour;
	stack<int> theStack;
	size_t bestTourCost = SIZE_MAX;
};

#endif // ITERATIVE1_H
