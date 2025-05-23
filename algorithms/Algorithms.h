#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include "../data_structures/DataStruct.h"
#include "ortools/linear_solver/linear_solver.h"
using namespace std;

/**
 * @brief Solves the Knapsack Problem using a Brute Force approach
 * 
 * This function tries all possible subsets of items to find the combination
 * that yields the highest profit without exceeding the specified weight limit.
 *
 * @param ds Reference to the data structure containing the available items.
 * @param maxWeight The maximum allowed total weight for the selected items.
 * @param selectedItems Output vector that will contain pointers to the selected items in the optimal subset.
 * @return The maximum profit achievable without exceeding the weight constraint.
 *
 * Time complexity: O(2^n) where n is the number of items
 * Space complexity: O(1) excluding the output vector
 *
 * @note This implementation uses bitmasking with an unsigned long long for efficiency,
 * which limits the number of items to 64 (due to the 64-bit size).
 * This is not a real limitation in practice, since brute-force has exponential
 * complexity and becomes too slow for more than ~25–30 items. (ex dataset5 would take around 10 min)
 */
int bruteForce(DataStruct &ds, int maxWeight, std::vector<const Item*>  &selectedItems);

/**
 * @brief Solves the Knapsack Problem using a Backtracking approach
 * 
 * This function implements a recursive backtracking solution with pruning.
 * It explores the decision tree of including or excluding each item while
 * avoiding suboptimal paths using suffixProfit for early pruning.
 * 
 * @param ds The DataStruct containing the items with their weights and profits
 * @param maxWeight The maximum weight capacity of the knapsack
 * @param selectedItems Vector to store the selected items in the optimal solution
 * @return int The maximum profit that can be achieved
 * 
 * Time complexity: O(2^n) in the worst case, but typically better due to pruning
 * Space complexity: O(n) for the recursion stack and suffix profit array
 */
int backtracking(DataStruct &ds, int maxWeight, std::vector<const Item*>  &selectedItems);

/**
 * @brief Solves the Knapsack Problem using a Dynamic Programming approach
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
 * Time complexity: O(n * W) where n is the number of items and W is the maximum weight
 * Space complexity: O(n * W) for the dynamic programming table
 */
 int dynamicProgramming(DataStruct &ds, int maxWeight, std::vector<const Item*> &selectedItems);

/**
 * @brief Solves the Knapsack Problem using profit/weight ratio greedy approach
 * 
 * This greedy algorithm sorts items by their profit-to-weight ratio in descending
 * order and selects items until the knapsack is full.
 * 
 * @param ds The DataStruct containing the items with their weights and profits
 * @param maxWeight The maximum weight capacity of the knapsack
 * @param maxProfit Reference to store the achieved profit
 * @param selectedItems Vector to store the selected items in the optimal solution
 *
 * Time complexity: O(n log n) where n is the number of items (due to sorting)
 * Space complexity: O(1) excluding the input data structure
 */
void greedyA(DataStruct &ds, int maxWeight, int &maxProfit, std::vector<const Item*> &selectedItems);

/**
 * @brief Solves the Knapsack Problem using profit-based greedy approach
 * 
 * This greedy algorithm sorts items by their profit in descending order
 * and selects items until the knapsack is full.
 * 
 * @param ds The DataStruct containing the items with their weights and profits
 * @param maxWeight The maximum weight capacity of the knapsack
 * @param maxProfit Reference to store the achieved profit
 * @param selectedItems Vector to store the selected items in the optimal solution
 *
 * Time complexity: O(n log n) where n is the number of items (due to sorting)
 * Space complexity: O(1) excluding the input data structure
 */
void greedyB(DataStruct &ds, int maxWeight, int &maxProfit, std::vector<const Item*> &selectedItems);

/**
 * @brief Combines multiple approximation algorithms for the Knapsack Problem
 * 
 * This function calls both:
 * - @ref greedyA
 * - @ref greedyB
 *
 * and returns the best result out of the two.
 * 
 * @param ds The DataStruct containing the items with their weights and profits
 * @param maxWeight The maximum weight capacity of the knapsack
 * @param maxProfit Reference to store the best approximated profit
 * @param selectedItems Vector to store the selected items in the optimal solution
 *
 * Time complexity: O(n log n) where n is the number of items
 * Space complexity: O(1) excluding the input data structure
 */
void approximate(DataStruct &ds, int maxWeight, int &maxProfit, std::vector<const Item*> &selectedItems);

void ilp(DataStruct &ds, int maxWeight, int &maxProfit, std::vector<const Item*> &selectedItems);


#endif //ALGORITHMS_H