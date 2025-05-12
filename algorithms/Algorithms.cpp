#include "Algorithms.h"

#include <algorithm>


/*************** Exhaustive (Brute-Force) Approach ****************/

// --> Brute Force
// Fornecido pelos professores na Ficha 2 Ex3 
int bruteForce(){
    // to do
    return 1;
}


// --> BackTracking 
// Mencionado no ppt Lecture 5 - Branch and Bounding & Backtracking
int backtracking(){
    // to do
    return 1;
}




/***************** Dynamic Programming Approach ******************/

int dynamicProgramming(){
    // to do
    return 1;
}




/******** Approximation Algorithms *********/

void greedyA(DataStruct &ds, int maxWeight, int &maxProfit){
    // Sort objects by decreasing profit/weight
    ds.sortByProfitPerWeight();

    // Pick first k objects while they still fit
    for (const Item* item : ds) {
        if (maxWeight == 0) {
            return;
        }
        if (maxWeight >= item->getWeight()) {
            maxWeight -= item->getWeight();
            maxProfit += item->getProfit();
        }
    }
}

void greedyB(DataStruct &ds, int maxWeight, int &maxProfit){
    // Sort the items in decreasing order of profit
    ds.sortByProfit();

    // Fill Knapsack until last item no longer fits
    for (const Item* item : ds) {
        if (maxWeight == 0) {
            return;
        }
        if (maxWeight >= item->getWeight()) {
            maxWeight -= item->getWeight();
            maxProfit += item->getProfit();
        }
    }
}

void approximate(DataStruct &ds, int maxWeight, int &maxProfit){
    int maxProfitA = 0, maxProfitB = 0;
    // Use Greedy algorithm A to compute approximation maxProfitA
    greedyA(ds, 100, maxProfitA);
    // Use Greedy algorithm B to compute approximation maxProfitB
    greedyA(ds, 100, maxProfitB);

    // Choose Best of maxProfitA and maxProfitB
    maxProfit = std::max(maxProfitA, maxProfitB);
}

/********* Integer Linear Programming Algorithm (ILP) *********/
