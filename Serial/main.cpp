#include <stdio.h>
#include <iostream>
#include "recursive.h"
#include "iterative1.h"
#include "iterative2.h"

using namespace std;
#define NUM_CITIES 4
size_t** ADJMAT = new size_t*[NUM_CITIES];

int main(){
	cout << "Initializing Map" << endl;
	for (int i = 0; i<NUM_CITIES; i++)
	{
		ADJMAT[i] = new size_t[NUM_CITIES];
		for (int j = 0; j<NUM_CITIES; j++)
		{
			if (i != j)
			{
				ADJMAT[i][j] = rand() % 20 + 1;
			}
			else {
				ADJMAT[i][j] = 0;
			}
		}
	}

	cout << "Map" << endl;
	for (int i = 0; i<NUM_CITIES; i++)
	{
		for (int j = 0; j<NUM_CITIES; j++)
		{
			cout << ADJMAT[i][j] << " ";
		}
		cout << endl;
	}


	cout << "Initializing First Tour" << endl;
	Tour tour = Tour(NUM_CITIES, 0, ADJMAT);

	cout << "Initializing Recursion Test" << endl;
	recursive recTest;
	recTest.DepthFirstSearch(tour);
	recTest.PrintBestTour();

	cout << endl;

	cout << "Initializing Iterative1 Test" << endl;
	iterative1 it1Test;
	it1Test.DepthFirstSearch(tour);
	it1Test.PrintBestTour();
    
	cout << endl;

	//iterative2 it2Test;
	//it2Test.PrintBestTour();
	//it2Test.PrintAdjMat();
	//it2Test.DepthFirstSearch(tour);
	//it2Test.PrintBestTour();
	delete ADJMAT;
	return 0;
}
