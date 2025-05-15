#include <iostream>
#include "algorithms/Algorithms.h"
#include "data_structures/DataStruct.h"
#include "menu/Menu.h"
using namespace std;

int main() {
    int pallets, maxWeight;

    DataStruct::getTruckAndPallets("../data/TruckAndPallets_08.csv", pallets, maxWeight);

    DataStruct ds;
    ds.initialize( "../data/Pallets_08.csv");

    // Use dynamic programming instead of approximation
    int maxProfit = dynamicProgramming(ds, maxWeight);
    cout << maxProfit << endl;

    Menu menu;
    menu.run();
    return 0;
}
