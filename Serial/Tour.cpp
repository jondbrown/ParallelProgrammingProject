#include "tour.h"



Tour::Tour()
{
	cityCount = 0;
	AddCity(0);
	tourCost = 0;
	maxNumCities = 1;
	adjMat = nullptr;
}

Tour::Tour(int numCities, int startingCity, size_t** adjMat)
{
	tourVector.push_back(startingCity);
	maxNumCities = numCities;
	for (int i = 0; i < numCities; i++)
	{
		tourVector.push_back(-1);
	}
	cityCount = 1;
	this->adjMat = adjMat;
}

Tour::Tour(const Tour & tourToCopy)
{
	tourVector = tourToCopy.GetTourVector();
	maxNumCities = tourToCopy.GetMaxNumCities();
	cityCount = tourToCopy.GetCityCount();
	tourCost = tourToCopy.GetTourCost();
	adjMat= tourToCopy.GetAdjMatPtr();
}


Tour::~Tour()
{
}

const vector<size_t>& Tour::GetTourVector() const
{
	// TODO: insert return statement here
	return tourVector;
}

size_t Tour::GetCityCount() const
{
	return cityCount;
}

size_t Tour::CalculateTotalTourCost() const
{
	int result = 0;
	for (int i = 0; i < maxNumCities - 1; i++)
	{
		result += adjMat[tourVector[i]][tourVector[i + 1]];
	}
	return result + adjMat[tourVector[maxNumCities - 1]][tourVector[0]];
}

size_t Tour::GetTourCost() const
{
	return tourCost;
}

size_t Tour::GetMaxNumCities() const
{
	return maxNumCities;
}

size_t ** Tour::GetAdjMatPtr() const
{
	return adjMat;
}

bool Tour::IsComplete() const
{
	return maxNumCities == cityCount;
}

void Tour::AddCity(size_t city)
{
	tourVector.insert(tourVector.begin() + cityCount, city);
	tourCost += adjMat[tourVector[cityCount - 1]][city];
	cityCount++;
}

void Tour::RemoveLastCity()
{
	tourVector.insert(tourVector.begin() + cityCount - 1, -1);
	tourCost -= adjMat[tourVector[cityCount - 2]][tourVector[cityCount - 1]];
	cityCount--;
}
