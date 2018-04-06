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
 void iterative2::PushCopy(Tour tour)
{
	 Tour newTour = tour;
	theStack.push(newTour);
}

//Checks whether or not the stack is empty
bool iterative2::Empty()
{
	return theStack.empty();
}

//pops the top partial tour off the stack
 Tour iterative2::Pop()
{
	Tour popTour = theStack.top();
	theStack.pop();
	return popTour;
}

//Adds the passed city to the passed tour
void iterative2::AddCity(Tour& currentTour, int city)
{
	currentTour.AddCity(city);
}

//Counts the number or cities in the passed tour
int iterative2::CityCount(Tour currentTour)
{
	return currentTour.GetCityCount();
}

//Checks if the passed tour is a better tour than the current bestTour
bool iterative2::BestTour(Tour currentTour)
{
	return currentTour.GetTourCost() + currentTour.GetLastCityCost()<bestTourCost;
}

//Updates the best tour to the passed tour
void iterative2::UpdateBestTour(Tour currentTour)
{
	bestTour = currentTour;
	bestTourCost = currentTour.GetTourCost() + currentTour.GetLastCityCost();
}

//Checks if it is feasible to add the passed city to the passed tour
bool iterative2::Feasible(Tour currentTour, int city)
{
	bool result = true;
	size_t** adjMat = currentTour.GetAdjMatPtr();
	vector<size_t> tourV = currentTour.GetTourVector();
	for (int i = 0; i<currentTour.GetCityCount(); i++)
	{
		if (tourV[i] == city || adjMat[tourV[currentTour.GetCityCount() - 1]][city] == 0)
		{
			result = false;
			break;
		}
	}
	return result;
}

//Removes the last city from the passed tour
void iterative2::RemoveLastCity(Tour& currentTour)
{
	currentTour.RemoveLastCity();
}

//Does a breadth first search to find the best tour using a stack of partial tours
void iterative2::DepthFirstSearch(Tour currentTour)
{
	//cout << "DepthFirstSearchStarting" << endl;
	PushCopy(currentTour);
	while (!Empty())
	{
		Tour currTour = Pop();
		if (currTour.IsComplete())
		{
			//cout << "if" << endl;
			if (BestTour(currTour))
			{
				//cout << "if" << endl;
				UpdateBestTour(currTour);
			}
		}
		else
		{
			for (int nbr = currTour.GetMaxNumCities() - 1; nbr >= 1; nbr--)
			{
				//cout << "Else" << endl;
				if (Feasible(currTour, nbr))
				{
					AddCity(currTour, nbr);
					PushCopy(currTour);
					RemoveLastCity(currTour);
				}
			}
		}
	}
	cout << "Done!" << endl;
}

//prints the bestTour member variable
void iterative2::PrintBestTour()
{
	cout << "Iterative2 Best Tour: ";
	vector<size_t> tour = bestTour.GetTourVector();
	for (size_t i = 0; i < bestTour.GetCityCount(); i++)
	{
		cout << tour[i] << " ";
	}
	cout << endl << "Total Cost: " << bestTourCost << endl;
}

