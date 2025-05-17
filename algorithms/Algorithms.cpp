#include "Algorithms.h"

#include <algorithm>
#include <iostream>
#include <ostream>


/*************** Exhaustive (Brute-Force) Approach ****************/

// --> Brute Force

// This implementation uses bitmasking with an unsigned long long for efficiency,
// which limits the number of items to 64 (due to the 64-bit size).
// This is not a real limitation in practice, since brute-force has exponential
// complexity and becomes too slow for more than ~25–30 items. (ex dataset5 would take around 10 min)
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
    greedyA(ds, maxWeight, maxProfitA);
    // Use Greedy algorithm B to compute approximation maxProfitB
    greedyA(ds, maxWeight, maxProfitB);

    // Choose Best of maxProfitA and maxProfitB
    maxProfit = std::max(maxProfitA, maxProfitB);
}

/********* Integer Linear Programming Algorithm (ILP) *********/
