#include <stdio.h>
#include <iostream>
#include "recursive.h"
#include "iterative1.h"
#include "iterative2.h"

using namespace std;
#define NUM_CITIES 4
size_t** ADJMAT = { 0 };

int main(){
	cout << "Initializing Map" << endl;
	for (int i = 0; i<NUM_CITIES; i++)
	{
		for (int j = 0; j<NUM_CITIES; j++)
		{
			if (i != j)
			{
				ADJMAT[i][j] = rand() % 20;
			}
			else {
				ADJMAT[i][j] = -1;
			}
		}
	}


	cout << "Initializing First Tour" << endl;
	Tour tour = Tour(NUM_CITIES, 0, ADJMAT);

	cout << "Initializing Recursion Test" << endl;
	recursive recTest;
	recTest.DepthFirstSearch(tour);
	recTest.PrintBestTour();

	cout << endl;

	//cout << "Initializing Iterative1 Test" << endl;
	iterative1 it1Test;
	//it1Test.DepthFirstSearch(tour, 0);
	//it1Test.PrintBestTour();
    
	cout << endl;

	//iterative2 it2Test;
	//it2Test.PrintBestTour();
	//it2Test.PrintAdjMat();
	//it2Test.DepthFirstSearch(tour);
	//it2Test.PrintBestTour();

	return 0;
}
