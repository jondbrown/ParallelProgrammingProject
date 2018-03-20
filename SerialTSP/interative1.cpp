#include "interative1.h"

interative1::interative1()
{
}

interative1::~interative1()
{
}

//------------------------------------------------------------
//STACK FUNCTIONS
bool interative1::Empty(){
	return theStack.empty();
}

void interative1::Push(int city){
	theStack.push(city);
}

int interative1::Pop(){
	int ret = theStack.top();
	theStack.pop();
	return ret;
}
//------------------------------------------------------------
//TOUR FUNCTIONS
int interative1::CityCount(int* tour){
	int count=0;
	for(int i=; i<NUM_CITIES, i++){
		if(tour[i]!=-1){
			count++;
		}else{
			break;
		}
	}
	return count;
}

void interative1::RemoveLastCity(int *tour){
	tour[CityCount(tour)-1]=-1;
}

void iterative1::AddCity(int* tour, int city){
	tour[CityCount(tour)] = city;
}

bool BestTour(int* tour);

void interative1::DepthFirstSearch(int* tour){
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
			if(CityCount(tour)==n){
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