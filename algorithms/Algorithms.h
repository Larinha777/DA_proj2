#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include "../data_structures/Item.h"

using namespace std;

void greedyA(vector <Item*> &v, int maxWeight, int &maxProfit);
void greedyB(vector <Item*> &v, int maxWeight, int &maxProfit);
void approximate(vector <Item*> &v, int maxWeight, int &maxProfit);



#endif //ALGORITHMS_H
