#pragma once
#include <stack>
#include <memory>

using namespace std;

//pushes partial tours into the stack instead of cities
class iterative2
{
public:
	#define NUM_CITIES 4
	#define HOMETOWN 0
	iterative2();
	~iterative2();

	//STACK FUNCTIONS
	int* PushCopy(int* tour);
	bool Empty();
	int* Pop();

	//TOUR FUNCTIONS
	void AddCity(int* currentTour, int city);
	int CityCount(int* currentTour);
	bool BestTour(int* currentTour);
	void UpdateBestTour(int* currentTour);
	bool Feasible(int* currentTour, int city);
	void RemoveLastCity(int* currentTour);
	void DepthFirstSearch(int* currentTour);

	//PRINT FUNCTIONS
	void PrintBestTour();
	void PrintAdjMat();

private:
	const int adjMat[NUM_CITIES][NUM_CITIES] = { { -1,1,3,8 },{ 4,-1,1,6 },{ 1,18,-1,10 },{ 7,4,12,-1 } };
	int bestTour[NUM_CITIES] = { 0, 1, 2, 3 };
	stack<int*> theStack;

};

