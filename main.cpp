#include <iostream>
#include "algorithms/Algorithms.h"
#include "data_structures/DataStruct.h"
using namespace std;

int main() {
    int pallets, maxWeight;

    DataStruct::getTruckAndPallets("../data/TruckAndPallets_05.csv", pallets, maxWeight);

    DataStruct ds;
    ds.initialize( "../data/Pallets_05.csv");

    int maxProfit;
    approximate(ds, maxWeight , maxProfit);
    cout << maxProfit << endl;

    return 0;
}
