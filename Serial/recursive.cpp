#include "recursive.h"
#include <iostream>
using namespace std;


recursive::recursive(void){}
recursive::~recursive(void){}

void recursive::PrintBestTour(){
	cout << "Recursive Best Tour: ";
	for(int i=0; i<NUM_CITIES; i++){
		cout << bestTour[i] << " ";
	}
	cout << endl;
}

void recursive::PrintAdjMat(){
	cout << "Recursive Adjacency Matrix:"<< endl;
	for(int i=0; i<NUM_CITIES; i++){
		for(int j=0; j<NUM_CITIES; j++){
		cout << adjMat[i][j] << " ";
		}
		cout << endl;
	}
}


//Return the current number of cities in the current tour
int recursive::CityCount(int* tour){
    int count=0;
    for(int i=0; i<NUM_CITIES; i++){
        if(tour[i]!=-1){
            count++;
        }else{
            break;
        }
    }
    return count;
}

//overwrites the best tour with the current tour
void recursive::UpdateBestTour(int* tour){
    for(int i=0; i<NUM_CITIES; i++){
        bestTour[i]= tour[i];
    }
}

//determines if a city is not included in the current tour
bool recursive::Feasible(int* tour, int city){
    bool result=true;
    for(int i=0; i<NUM_CITIES; i++){
        if(tour[i]==city){
            result = false;   
            break;
        }
    }
    return result;
}

//adds city to current tour
void recursive::AddCity(int* tour, int city){
    tour[CityCount(tour)]=city;
}

//removes last city in tour
void recursive::RemoveLastCity(int* tour, int city){
    tour[CityCount(tour)-1]=-1;
}

//determines if current tour is better than best tour
bool recursive::BestTour(int* tour){
    int newTour = 0;
    int currentTour = 0;
    for(int i=0; i<NUM_CITIES-1; i++){
        newTour += adjMat[tour[i]][tour[i+1]];
        currentTour += adjMat[bestTour[i]][bestTour[i+1]];
    }
    //add distance from last city to HOMETOWN
    newTour += adjMat[tour[NUM_CITIES-1]][HOMETOWN];
    currentTour += adjMat[bestTour[NUM_CITIES-1]][HOMETOWN];
    
    return newTour<currentTour;
}

//main recursive function
void recursive::DepthFirstSearch(int* tour){
    int city;

    if(CityCount(tour)==NUM_CITIES){
        if(BestTour(tour)){
            UpdateBestTour(tour);
        }
    }else{
        for (city=0; city<NUM_CITIES; city++){
            if(Feasible(tour, city)){
                AddCity(tour, city);
                DepthFirstSearch(tour);
                RemoveLastCity(tour, city);
            }
        }
    }
}

