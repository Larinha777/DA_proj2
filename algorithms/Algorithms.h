#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include "../data_structures/DataStruct.h"
using namespace std;


int bruteForce(DataStruct &ds, int maxWeight, std::vector<const Item*>  &selectedIndices);
int backtracking(DataStruct &ds, int maxWeight, std::vector<const Item*>  &selectedIndices);

void greedyA(DataStruct &ds, int maxWeight, int &maxProfit);
void greedyB(DataStruct &ds, int maxWeight, int &maxProfit);
void approximate(DataStruct &ds, int maxWeight, int &maxProfit);



#endif //ALGORITHMS_H
