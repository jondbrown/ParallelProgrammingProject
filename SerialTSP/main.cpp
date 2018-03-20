#include <stdio.h>
#include <iostream>
#include <recursive.h>
#include <iterative1.h>

using namespace std;


int main(){
	
	int tour[4]={0,-1,-1,-1};
	recursive recTest;
	recTest.PrintBestTour();
	recTest.PrintAdjMat();
	recTest.DepthFirstSearch(tour);
	recTest.PrintBestTour();
    
	cout << endl;
	
	iterative1 it1Test;
	it1Test.PrintBestTour();
	it1Test.PrintAdjMat();
	it1Test.DepthFirstSearch(tour);
	it1Test.PrintBestTour();
}
