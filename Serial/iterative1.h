#ifndef ITERATIVE1_H
#define ITERATIVE1_H
#include <stack>

using namespace std;

class iterative1
{
public:
	#define NUM_CITIES 4
	#define HOMETOWN 0
	iterative1();
	~iterative1();
	
	//STACK FUNCTIONS
	bool Empty();
	void Push(int city);
	int Pop();
	
	//TOUR FUNCTIONS
	int CityCount(int* tour);
	
	void RemoveLastCity(int* tour);
	
	void AddCity(int* tour, int city);
	
	bool BestTour(int* tour);
	
	void UpdateBestTour(int* tour);
	
	bool Feasible(int* tour, int city);
	
	void DepthFirstSearch(int* tour);
	
	//PRINT FUNCTIONS
	void PrintBestTour();
	void PrintAdjMat();
	
private:
	const int adjMat[NUM_CITIES][NUM_CITIES] = {{-1,1,3,8},{4,-1,1,6},{1,18,-1,10},{7,4,12,-1}};
	int bestTour[NUM_CITIES] = {0, 1, 2, 3};
	stack<int> theStack;

};

#endif // ITERATIVE1_H
