#include <iostream>
#include "iterative1.h"

iterative1::iterative1(){}

iterative1::~iterative1(){}

//------------------------------------------------------------
//STACK FUNCTIONS
bool iterative1::Empty(){
	return theStack.empty();
}

void iterative1::Push(int city){
	theStack.push(city);
}

int iterative1::Pop(){
	int ret = theStack.top();
	theStack.pop();
	return ret;
}
//------------------------------------------------------------
//TOUR FUNCTIONS
int iterative1::CityCount(Tour& tour){
	return tour.GetCityCount();
}

void iterative1::RemoveLastCity(Tour& tour){
	tour.RemoveLastCity();
}

void iterative1::AddCity(Tour& tour, int city){
	tour.AddCity(city);
}

//checks if current tour cost is less than best tour
bool iterative1::BestTour(Tour& tour){
	return tour.GetTourCost()+tour.GetLastCityCost()<bestTourCost;
}

void iterative1::UpdateBestTour(Tour& tour){
	bestTour = tour;
	bestTourCost = tour.GetTourCost()+tour.GetLastCityCost(); 
}
	
bool iterative1::Feasible(Tour& tour, int city){
	bool result = true;
	size_t** adjMat = tour.GetAdjMatPtr(); //????add to iterative1 instance to eliminate function call????
	vector<size_t> tourV = tour.GetTourVector();
	for (int i = 0; i<tour.GetCityCount(); i++)
	{
		if (adjMat[tourV[tour.GetCityCount() - 1]][city]==0 || tourV[i] == city) //?????REVERSE CONDITION ORDER??????
		{
			result = false;
			break;
		}
	}
	return result;
}

void iterative1::DepthFirstSearch(Tour tour){
	int city;
	//push all cities onto stack
	for(city = tour.GetMaxNumCities()-1; city>=1; city--){
		Push(city);
	}
	while(!Empty()){
		city = Pop();
		if(city==0){ //????? shoule be changed to starting city????
			RemoveLastCity(tour);
		}else{
			AddCity(tour, city);
			if(tour.IsComplete()){
				if(BestTour(tour)){
					UpdateBestTour(tour);
				}
				RemoveLastCity(tour);
			}else{
				Push(0);
				for(int nbr=tour.GetMaxNumCities()-1; nbr>=1; nbr--){
					if(Feasible(tour, nbr)){
						Push(nbr);
					}//if Feasible
				}
			}//if CityCount
		}//if city
	}//while !Empty
}

//------------------------------------------------------------
//PRINT FUCTIONS
void iterative1::PrintBestTour(){
	cout << "Iterative1 Best Tour: ";
	vector<size_t> tour = bestTour.GetTourVector();
	for (size_t i = 0; i < bestTour.GetCityCount(); i++)
	{
		cout << tour[i] << " ";
	}
	cout << endl << "Total Cost: " << bestTourCost << endl;
}
