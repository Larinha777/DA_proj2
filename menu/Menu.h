#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "../data_structures/DataStruct.h"

class Menu {
private:
    int selectedItemIndex;    ///< The index of the currently selected menu item.
    std::string currentColor; ///< The current text color code used for highlighting selections.
    std::vector<std::string> items;
    std::string truckFile_;
    std::string palletFile_;

    // Generic selector
    int selectFromList(const std::vector<std::string>& options, const std::string& prompt, int initialIndex = 0);
    void handleSelection();

    // Data-set and algorithm
    void changeDataSet();
    void runAlgorithmMenu();

    // Algorithm runners
    void runBruteForce();
    void runBacktracking();
    void runDynamicProgramming();

    // Util
    void processArrowKeyInput(int& index, int maxIndex) const;
    bool loadData(int &palletCount, int &maxWeight, DataStruct &ds);


public:

    Menu();
    void run();
};

#endif // MENU_H