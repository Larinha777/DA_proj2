#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include "../data_structures/DataStruct.h"
#include "ortools/linear_solver/linear_solver.h"
using namespace std;


int bruteForce(DataStruct &ds, int maxWeight, std::vector<const Item*>  &selectedIndices);
int backtracking(DataStruct &ds, int maxWeight, std::vector<const Item*>  &selectedIndices);

/**
 * @brief Solves the Knapsack Problem using Dynamic Programming approach
 * 
 * This function implements a bottom-up dynamic programming solution to the 0/1 Knapsack Problem.
 * It creates a table where dp[i][w] represents the maximum profit that can be obtained
 * using the first i items with a weight capacity of w.
 * 
 * @param ds The DataStruct containing the items with their weights and profits
 * @param maxWeight The maximum weight capacity of the knapsack
 * @param selectedItems Vector to store the selected items in the optimal solution
 * @return int The maximum profit that can be achieved
 * 
 * @time_complexity O(n * W) where n is the number of items and W is the maximum weight
 * @space_complexity O(n * W) for the dynamic programming table
 */
 int dynamicProgramming(DataStruct &ds, int maxWeight, std::vector<const Item*> &selectedItems);

void greedyA(DataStruct &ds, int maxWeight, int &maxProfit, std::vector<const Item*> &selectedItems);
void greedyB(DataStruct &ds, int maxWeight, int &maxProfit, std::vector<const Item*> &selectedItems);
void approximate(DataStruct &ds, int maxWeight, int &maxProfit, std::vector<const Item*> &selectedItems);

void ilp(DataStruct &ds, int maxWeight, int &maxProfit, std::vector<const Item*> &selectedItems);


#endif //ALGORITHMS_H
