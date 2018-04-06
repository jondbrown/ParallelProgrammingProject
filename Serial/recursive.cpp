#include "recursive.h"
#include <iostream>
using namespace std;


recursive::recursive(void) { bestTourCost = SIZE_MAX; }
recursive::~recursive(void){}

void recursive::PrintBestTour(){
	cout << "Recursive Best Tour: ";
	vector<size_t> tour = bestTour.GetTourVector();
	for (size_t i = 0; i < bestTour.GetCityCount(); i++)
	{
		cout << tour[i] << " ";
	}
	cout << endl << "Total Cost: " << bestTourCost << endl;
}


//Return the current number of cities in the current tour
int recursive::CityCount(Tour tour){
	return tour.GetCityCount();
}

//overwrites the best tour with the current tour
void recursive::UpdateBestTour(Tour tour){
	bestTour = tour;
	bestTourCost = tour.GetTourCost() + tour.GetLastCityCost();
}

//determines if a city is not included in the current tour
bool recursive::Feasible(Tour tour, int city){
	bool result = true;
	size_t** adjMat = tour.GetAdjMatPtr();
	vector<size_t> tourV = tour.GetTourVector();
	for (int i = 0; i<tour.GetCityCount(); i++)
	{
		if (tourV[i] == city || adjMat[tourV[tour.GetCityCount() - 1]][city]==0)
		{
			result = false;
			break;
		}
	}
	return result;
}

//adds city to current tour
void recursive::AddCity(Tour& tour, int city){
    tour.AddCity(city);
}

//removes last city in tour
void recursive::RemoveLastCity(Tour& tour){
	tour.RemoveLastCity();
}

//determines if current tour is better than best tour
bool recursive::BestTour(Tour tour){
	return tour.GetTourCost() + tour.GetLastCityCost() < bestTourCost;
}

//main recursive function
void recursive::DepthFirstSearch(Tour& tour){
    
	int city;

    if(tour.IsComplete()){
        if(BestTour(tour)){
            UpdateBestTour(tour);
        }
    }else{
        for (city=0; city<tour.GetMaxNumCities(); city++){
            if(Feasible(tour, city)){
                AddCity(tour, city);
                DepthFirstSearch(tour);
                RemoveLastCity(tour);
            }
        }
    }
}

