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
int iterative1::CityCount(int* tour){
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

void iterative1::RemoveLastCity(int *tour){
	tour[CityCount(tour)-1]=-1;
}

void iterative1::AddCity(int* tour, int city){
	tour[CityCount(tour)] = city;
}

bool iterative1::BestTour(int* tour){
	int newTour=0;
	int currentTour=0;
	for(int i=0; i<NUM_CITIES-1; i++){
		newTour += adjMat[tour[i]][tour[i+1]];
        currentTour += adjMat[bestTour[i]][bestTour[i+1]];
	}
	newTour += adjMat[tour[NUM_CITIES-1]][HOMETOWN];
    currentTour += adjMat[bestTour[NUM_CITIES-1]][HOMETOWN];
	
	return newTour<currentTour;
}

void iterative1::UpdateBestTour(int* tour){
	for(int i=0; i<NUM_CITIES; i++){
		bestTour[i]= tour[i];
	}
}
	
bool iterative1::Feasible(int* tour, int city){
	bool result=true;
	for(int i=0; i<NUM_CITIES; i++){
		if(tour[i]==city){
			result = false;   
			break;
		}
	}
	return result;
}

void iterative1::DepthFirstSearch(int* tour){
	int city;
	for(city =NUM_CITIES-1; city>=1; city--){
		Push(city);
	}
	while(!Empty()){
		city= Pop();
		if(city==-1){
			RemoveLastCity(tour);
		}else{
			AddCity(tour, city);
			if(CityCount(tour)==NUM_CITIES){
				if(BestTour(tour)){
					UpdateBestTour(tour);
				}
				RemoveLastCity(tour);
			}else{
				Push(-1);
				for(int nbr=NUM_CITIES-1; nbr>=1; nbr--){
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
	cout << "Iterative 1 Best Tour: ";
	for(int i=0; i<NUM_CITIES; i++){
		cout << bestTour[i] << " ";
	}
	cout << endl;
}

void iterative1::PrintAdjMat(){
	cout << "Iterative 1 Adjacency Matrix:"<< endl;
	for(int i=0; i<NUM_CITIES; i++){
		for(int j=0; j<NUM_CITIES; j++){
		cout << adjMat[i][j] << " ";
		}
		cout << endl;
	}
}