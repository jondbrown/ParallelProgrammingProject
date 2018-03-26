#include <iostream>
#include "iterative2.h"

using namespace std;

iterative2::iterative2()
{
}


iterative2::~iterative2()
{
}

//Copies the passed tour and pushes it into the stack
int * iterative2::PushCopy(int * tour)
{
	std::array<int, 4> newTour = tour;
	theStack.push(newTour);
	return newTour;
}

//Checks whether or not the stack is empty
bool iterative2::Empty()
{
	return theStack.empty();
}

//pops the top partial tour off the stack
int * iterative2::Pop()
{
	int* popTour = theStack.top();
	theStack.pop();
	return popTour;
}

//Adds the passed city to the passed tour
void iterative2::AddCity(int * currentTour, int city)
{
	currentTour[CityCount(currentTour)] = city;
}

//Counts the number or cities in the passed tour
int iterative2::CityCount(int * currentTour)
{
	int count = 0;
	for (int i = 0; i < NUM_CITIES; i++)
	{
		if (currentTour[i] != -1)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	return count;
}

//Checks if the passed tour is a better tour than the current bestTour
bool iterative2::BestTour(int * currentTour)
{
	int newTour = 0;
	//current tour score
	int cTourScore = 0;
	for (int i = 0; i < NUM_CITIES - 1; i++)
	{
		newTour += adjMat[currentTour[i]][currentTour[i + 1]];
		currentTour += adjMat[bestTour[i]][bestTour[i + 1]];
	}
	newTour += adjMat[currentTour[NUM_CITIES - 1]][currentTour[HOMETOWN]];
	cTourScore += adjMat[bestTour[NUM_CITIES - 1]][currentTour[HOMETOWN]];
	return newTour < cTourScore;
}

//Updates the best tour to the passed tour
void iterative2::UpdateBestTour(int * currentTour)
{
	for (int i = 0; i < NUM_CITIES; i++) 
	{
		bestTour[i] = currentTour[i];
	}
}

//Checks if it is feasible to add the passed city to the passed tour
bool iterative2::Feasible(int * currentTour, int city)
{
	bool result = true;
	for (int i = 0; i < NUM_CITIES; i++) {
		if (currentTour[i] == city) {
			result = false;
			break;
		}
	}
	return result;
}

//Removes the last city from the passed tour
void iterative2::RemoveLastCity(int * currentTour)
{
	currentTour[CityCount(currentTour) - 1] = -1;
}

//Does a breadth first search to find the best tour using a stack of partial tours
void iterative2::DepthFirstSearch(int * currentTour)
{
	cout << "DepthFirstSearchStarting" << endl;
	PushCopy(currentTour);
	while (!Empty())
	{
		int* currTour = Pop();
		if (CityCount(currTour) == NUM_CITIES)
		{
			cout << "if" << endl;
			if (BestTour(currTour))
			{
				UpdateBestTour(currTour);
			}
		}
		else
		{
			for (int nbr = NUM_CITIES - 1; nbr >= 1; nbr--)
			{
				cout << "Else" << endl;
				if (Feasible(currTour, nbr))
				{
					AddCity(currTour, nbr);
					PushCopy(currTour);
					RemoveLastCity(currTour);
				}
			}
		}
		delete currTour;
		currTour = nullptr;
	}
	cout << "Done!" << endl;
}

//prints the bestTour member variable
void iterative2::PrintBestTour()
{
	cout << "Iterative 2 Best Tour: ";
	for (int i = 0; i < NUM_CITIES; i++) {
		cout << bestTour[i] << " ";
	}
	cout << endl;
}

//Prints the adjMat variable
void iterative2::PrintAdjMat()
{
	cout << "Iterative 2 Adjacency Matrix:" << endl;
	for (int i = 0; i < NUM_CITIES; i++) {
		for (int j = 0; j < NUM_CITIES; j++) {
			cout << adjMat[i][j] << " ";
		}
		cout << endl;
	}
}
