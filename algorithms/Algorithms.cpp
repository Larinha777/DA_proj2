#include "Algorithms.h"

#include <vector>
#include <algorithm>
#include <iostream>


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

void greedyA(vector <Item*> &v, int maxWeight, int &maxProfit){
    // Sort objects by decreasing profit of pi/wi
    std::sort(v.begin(), v.end(), [](const Item* i, const Item* j) {
        return i->getWeightByProfit() > j->getWeightByProfit();
    });

    // Pick first k objects while they still fit
    for (const Item* item : v) {
        if (maxWeight == 0) {
            return;
        }
        if (maxWeight >= item->getWeight()) {
            maxWeight -= item->getWeight();
            maxProfit += item->getProfit();
        }
    }
}

void greedyB(vector <Item*> &v, int maxWeight, int &maxProfit){
    // Sort the items in decreasing order of profit
    std::sort(v.begin(), v.end(), [](const Item* i, const Item* j) {
        return i->getProfit() > j->getProfit();
    });

    // Fill Knapsack until last item no longer fits
    for (const Item* item : v) {
        if (maxWeight == 0) {
            return;
        }
        if (maxWeight >= item->getWeight()) {
            maxWeight -= item->getWeight();
            maxProfit += item->getProfit();
        }
    }
}

void approximate(vector <Item*> &v, int maxWeight, int &maxProfit){
    int maxProfitA = 0, maxProfitB = 0;
    // Use Greedy algorithm A to compute approximation maxProfitA
    greedyA(v, 100, maxProfitA);
    // Use Greedy algorithm B to compute approximation maxProfitB
    greedyA(v, 100, maxProfitB);

    // Choose Best of maxProfitA and maxProfitB
    maxProfit = std::max(maxProfitA, maxProfitB);
}

/********* Integer Linear Programming Algorithm (ILP) *********/
