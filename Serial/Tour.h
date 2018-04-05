#include <vector>

#pragma once

using namespace std;

class Tour
{
public:
	Tour();
	Tour(int numCities, int startingCity, size_t** adjMat);
	Tour(const Tour& tourToCopy);
	~Tour();
	const vector<size_t>& GetTourVector() const;
	size_t GetCityCount() const;
	size_t CalculateTotalTourCost() const;
	size_t GetTourCost() const;
	size_t GetMaxNumCities() const;
	size_t ** GetAdjMatPtr() const;
	//checks the fullness of tourVector
	bool IsComplete() const;	
	//create City Class Eventually to pass into this method
	void AddCity(size_t city);
	int GetLastCityCost();
	void RemoveLastCity();
	size_t GetHometown() const;
private:
	std::vector<size_t> tourVector;
	size_t** adjMat;
	//is the tour full of cities?
	size_t cityCount;
	size_t tourCost;
	size_t maxNumCities;
	size_t hometown;


};

