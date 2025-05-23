#include "Algorithms.h"

#include <algorithm>
#include <iostream>
#include <ostream>
#include <iostream>
#include "ortools/linear_solver/linear_solver.h"
using namespace std;
using namespace operations_research;


/*************** Exhaustive (Brute-Force) Approach ****************/

// --> Brute Force
int bruteForce(DataStruct &ds, int maxWeight, std::vector<const Item*> &selectedItems) {
    const auto& items = ds.getItems();
    int n = items.size();

    int best = 0;
    unsigned long long bestMask = 0;
    unsigned long long total = 1ULL << n;

    for (unsigned long long mask = 0; mask < total; ++mask) {
        int w = 0, p = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1ULL << i)) {
                w += items[i]->getWeight();
                if (w > maxWeight) {
                    p = -1;
                    break;
                }
                p += items[i]->getProfit();
            }
        }
        if (p > best) {
            best = p;
            bestMask = mask;
        }
    }

    selectedItems.clear();
    for (int i = 0; i < n; ++i) {
        if (bestMask & (1ULL << i)) {
            selectedItems.push_back(items[i]);
        }
    }

    return best;
}

// --> BackTracking

static void btRec(const vector<const Item*>& items, int idx, int currW, int currP, int capacity, int &bestP, const vector<int>& suffixProfit, vector<const Item*>& currSet, vector<const Item*>& bestSet){
    if (currW > capacity) return;
    if (currP + suffixProfit[idx] <= bestP) return;
    if (idx == (int)items.size()) {
        if (currP > bestP) {
            bestP = currP;
            bestSet = currSet;
        };
        return;
    }

    currSet.push_back(items[idx]);
    btRec(items, idx+1, currW + items[idx]->getWeight(), currP + items[idx]->getProfit(), capacity, bestP, suffixProfit, currSet, bestSet);
    currSet.pop_back();

    btRec(items, idx+1, currW, currP, capacity, bestP, suffixProfit, currSet, bestSet);
}

int backtracking(DataStruct &ds, int capacity, std::vector<const Item*> &selectedItems){
    vector<const Item*> items(ds.begin(), ds.end());
    int n = items.size();
    vector<int> suffixProfit(n+1, 0);
    for (int i = n-1; i >= 0; --i) suffixProfit[i] = suffixProfit[i+1] + items[i]->getProfit();

    int bestP = 0;
    std::vector<const Item*> currSet, bestSet;
    btRec(items, 0, 0, 0, capacity, bestP, suffixProfit, currSet, bestSet);
    selectedItems = std::move(bestSet);
    return bestP;
}


/***************** Dynamic Programming Approach ******************/

int dynamicProgramming(DataStruct &ds, int maxWeight, std::vector<const Item*> &selectedItems) {
    std::vector<const Item*> items;
    for (const Item* item : ds) {
        items.push_back(item);
    }

    int n = items.size();

    // Create table dp[i][w] for max profit with first i items and weight capacity w
    std::vector<std::vector<int>> dp(n + 1, std::vector<int>(maxWeight + 1, 0));

    // Build table
    for (int i = 1; i <= n; i++) {
        const Item* item = items[i-1];
        int weight = item->getWeight();
        int profit = item->getProfit();

        for (int w = 0; w <= maxWeight; w++) {
            // If current item's weight > w, can't be included
            if (weight > w) {
                dp[i][w] = dp[i-1][w];
            }
            // Otherwise, take the maximum of:
            // 1. Not including the current item
            // 2. Including the current item and adding its profit
            else {
                dp[i][w] = std::max(dp[i-1][w], dp[i-1][w-weight] + profit);
            }
        }
    }

    // Backtrack to find which items were selected (runtime doesn't seem to be affected)
    selectedItems.clear();
    int w = maxWeight;
    for (int i = n; i > 0; i--) {
        // If the result comes from including this item
        if (dp[i][w] != dp[i-1][w]) {
            selectedItems.push_back(items[i-1]);
            w -= items[i-1]->getWeight();
        }
    }

    return dp[n][maxWeight];
}




/******** Approximation Algorithms *********/

void greedyA(DataStruct &ds, int maxWeight, int &maxProfit, std::vector<const Item*> &selectedItems){
    // Sort objects by decreasing profit/weight
    ds.sortByProfitPerWeight();

    // Pick first k objects while they still fit
    for (const Item* item : ds) {
        if (maxWeight == 0) {
            return;
        }
        if (maxWeight >= item->getWeight()) {
            selectedItems.push_back(item);
            maxWeight -= item->getWeight();
            maxProfit += item->getProfit();
        }
    }
}

void greedyB(DataStruct &ds, int maxWeight, int &maxProfit, std::vector<const Item*> &selectedItems){
    // Sort the items in decreasing order of profit
    ds.sortByProfit();

    // Fill Knapsack until last item no longer fits
    for (const Item* item : ds) {
        if (maxWeight == 0) {
            return;
        }
        if (maxWeight >= item->getWeight()) {
            selectedItems.push_back(item);
            maxWeight -= item->getWeight();
            maxProfit += item->getProfit();
        }
    }
}

void approximate(DataStruct &ds, int maxWeight, int &maxProfit, std::vector<const Item*> &selectedItems){
    int maxProfitA = 0, maxProfitB = 0;
    std::vector<const Item*> selectedItemsA, selectedItemsB;
    // Use Greedy algorithm A to compute approximation maxProfitA
    greedyA(ds, maxWeight, maxProfitA, selectedItemsA);
    // Use Greedy algorithm B to compute approximation maxProfitB
    greedyA(ds, maxWeight, maxProfitB, selectedItemsB);

    // Choose Best of maxProfitA and maxProfitB
    if (maxProfitA > maxProfitB) {
        maxProfit = maxProfitA;
        selectedItems = std::move(selectedItemsA);
    } else {
        maxProfit = maxProfitB;
        selectedItems = std::move(selectedItemsB);
    }
}

/********* Integer Linear Programming Algorithm (ILP) *********/


void ilp(DataStruct &ds, int maxWeight, int &maxProfit, std::vector<const Item*> &selectedItems) {
    MPSolver solver("Knapsack", MPSolver::CBC_MIXED_INTEGER_PROGRAMMING);

    std::vector<const MPVariable*> x;
    for (const Item* item : ds) {
        x.push_back(solver.MakeIntVar(0, 1, "x" + std::to_string(item->getId()-1)));
    }

    MPConstraint* constraint = solver.MakeRowConstraint(0, maxWeight);
    for (const Item* item : ds) {
        constraint->SetCoefficient(x[item->getId()-1], item->getWeight());
    }

    MPObjective* objective = solver.MutableObjective();
    for (const Item* item : ds) {
        objective->SetCoefficient(x[item->getId()-1], item->getProfit());
    }
    objective->SetMaximization();

    solver.Solve();

    double val = objective->Value();
    maxProfit = (int) val;

    for (const Item* item : ds) {
        if (x[item->getId()-1]->solution_value() > 0.5)
            selectedItems.push_back(item);
    }
}
