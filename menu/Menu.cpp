#include "Menu.h"
#include "tc.h"

#include <fstream>
#include <iostream>

#include <regex>
#include <unistd.h>
#include <vector>

#include <chrono>
#include "../algorithms/Algorithms.h"
#include "../data_structures/DataStruct.h"

#define MAX_PALLETS_BRUTEFORCE 20
#define MAX_PALLETS_BACKTRACKING 25

using namespace std;

//Menu
Menu::Menu()
  : truckFile_("NO_DEFAULT"),
    palletFile_("NO_DEFAULT"),
    items({
      "1. Change Dataset",
      "2. Run Algorithm",
      "0. Exit"
    }),
    selectedItemIndex(0),
    currentColor(TC_MAG)
{}

void Menu::run() {
    enable_raw_mode();
    hide_cursor();
    changeDataSet();
    while (true) {
        selectedItemIndex = selectFromList(items, "===== Truck Pallet Packing (0/1 Knapsack) =====");
        handleSelection();
    }
    disable_raw_mode();
    show_cursor();
}

void Menu::handleSelection() {
    switch (selectedItemIndex) {
        case 0: changeDataSet(); break;
        case 1: runAlgorithmMenu(); break;
        case 2:
        case 3: tc_clear_screen(); exit(0); break;
        default: break;
    }
}

int Menu::selectFromList(const vector<string>& options, const string& prompt, int initialIndex) {
    int index = initialIndex;
    while (true) {
        tc_clear_screen();
        cout << prompt << endl;
        for (int i = 0; i < (int)options.size(); ++i) {
            if (i == index) cout << currentColor << "> " << options[i] << TC_NRM << "\n";
            else cout << "  " << options[i] << "\n";
        }

        char c = getchar();
        if (c == '\n') { return index;
        } else if (c == '\033') { processArrowKeyInput(index, options.size());
        } else if (c >= '1' && c <= '0' + (char)options.size()) { return c - '1';}
    }
}

void Menu::changeDataSet() {

    vector<string> dataOptions;
    for (int i = 1; i <= 10; ++i) {
        char buf[32];
        std::snprintf(buf, sizeof(buf), "Dataset %02d", i);
        dataOptions.emplace_back(buf);
    }
    int choice = selectFromList( dataOptions, "Choose which dataset to load:");
    char tbuf[64], pbuf[64];
    std::snprintf(tbuf, sizeof(tbuf),"../data/TruckAndPallets_%02d.csv", choice + 1);
    std::snprintf(pbuf, sizeof(pbuf),"../data/Pallets_%02d.csv", choice + 1);
    truckFile_  = tbuf;
    palletFile_ = pbuf;

    DataStruct ds;
    int pallets, maxW;
    if (!loadData(pallets, maxW, ds))return;

    tc_clear_screen();
    cout << "Loaded:\n " << TC_GRN  << truckFile_ << "\n " << palletFile_ << TC_NRM <<"\nPress Enter to continue...";
    getchar();
}

void Menu::runAlgorithmMenu() {
    vector<string> algos = {
        "1. Brute-Force",
        "2. Backtracking",
        "3. Dynamic Programming",
        "4. Approximate Algorithm",
        "5. ILP Algorithm",
        "6. Run All Algorithms",
        "0. Return "
      };
    int choice = selectFromList(algos, "Select algorithm to run:");
    switch (choice) {
        case 0: runBruteForce(false); break;
        case 1: runBacktracking(false); break;
        case 2: runDynamicProgramming(false); break;
        case 3: runApproximate(false); break;
        case 4: runILP(false); break;
        case 5: runAllAlgorithms(); break;
        default: break;
    }
}


//Algorithms

void Menu::runBruteForce(bool all) {
    int pallets, maxW;
    DataStruct ds;
    if (!loadData(pallets, maxW, ds)) return;

    if (pallets > MAX_PALLETS_BRUTEFORCE) {
        tc_clear_screen();
        std::cout << TC_YEL << "[Backtracking] Too many pallets (" << pallets << ").\n"
            << "Maximum allowed is " << MAX_PALLETS_BRUTEFORCE << ".\n";

        if (!all) {
            std::cout << "Please choose a more efficient algorithm.\n";
        }

        std::cout << TC_NRM << "Press Enter to continue...";

        if (all) logToCSV("Brute-Force", -1, -1, pallets);
        getchar();
        return;
    }

    std::vector<const Item*>  selectedItems;
    auto t0 = chrono::high_resolution_clock::now();
    int best = bruteForce(ds, maxW, selectedItems);
    auto t1 = chrono::high_resolution_clock::now();

    double secs = chrono::duration<double>(t1 - t0).count();
    tc_clear_screen();
    cout << "[Brute-Force]\n"
         << "  Max Profit = " << best << "\n"
         << "  Time = " << secs << " s\n"
         << "  Items Used:\n ";
    for (auto item : selectedItems) {
        cout << " " << item->getId()
             << ", " << item->getWeight()
             << ", " << item->getProfit() << "\n";
    }

    logResultToFile("Brute-Force", best, secs, selectedItems);
    if (all) logToCSV("Brute-Force", best, secs, pallets);
    cout << "Press Enter to continue...";
    getchar();
}

void Menu::runBacktracking(bool all) {
    int pallets, maxW;
    DataStruct ds;
    if (!loadData(pallets, maxW, ds))return;

    if (pallets > MAX_PALLETS_BACKTRACKING) {
        tc_clear_screen();
        std::cout << TC_YEL << "[Backtracking] Too many pallets (" << pallets << ").\n"
            << "Maximum allowed is " << MAX_PALLETS_BACKTRACKING << ".\n";

        if (!all) {
            std::cout << "Please choose a more efficient algorithm.\n";
        }

        std::cout << TC_NRM << "Press Enter to continue...";


        if (all) logToCSV("Backtracking", -1, -1, pallets);
        getchar();
        return;
    }

    std::vector<const Item*> selectedItems;
    auto t0 = chrono::high_resolution_clock::now();
    int best = backtracking(ds, maxW, selectedItems);
    auto t1 = chrono::high_resolution_clock::now();

    double secs = chrono::duration<double>(t1 - t0).count();
    tc_clear_screen();
    cout << "[Backtracking]\n"
         << "  Max Profit = " << best << "\n"
         << "  Time = " << secs << " s\n"
         << "  Items Used:\n ";
    for (auto item : selectedItems) {
        cout << " " << item->getId()
             << ", " << item->getWeight()
             << ", " << item->getProfit() << "\n";
    }

    logResultToFile("Backtracking", best, secs, selectedItems);
    if (all) logToCSV("Backtracking", best, secs, pallets);
    cout << "Press Enter to continue...";
    getchar();
}

void Menu::runApproximate(bool all) {
    int pallets, maxW;
    DataStruct ds;
    if (!loadData(pallets, maxW, ds)) return;

    int maxProfit = 0;
    std::vector<const Item*> selectedItems;
    auto t0 = chrono::high_resolution_clock::now();
    approximate(ds, maxW, maxProfit, selectedItems);
    auto t1 = chrono::high_resolution_clock::now();

    double secs = chrono::duration<double>(t1 - t0).count();
    tc_clear_screen();
    cout << "[Approximate Algorithm]" <<  "\n"
         << "  Max Profit: "  << maxProfit  << "\n"
         << "  Time = " << secs << " s\n"
         << "  Items Used:\n ";
         for (auto item : selectedItems) {
             cout << " " << item->getId()
                 << ", " << item->getWeight()
                 << ", " << item->getProfit() << "\n";
         }

    logResultToFile("Approximate", maxProfit, secs, selectedItems);
    cout << "Press Enter to return...";

    if (all) logToCSV("Approximate", maxProfit, secs, pallets);
    getchar();
}

void Menu::runDynamicProgramming(bool all) {
    int pallets, maxW;
    DataStruct ds;
    if (!loadData(pallets, maxW, ds)) return;

    std::vector<const Item*> selectedItems;
    auto t0 = chrono::high_resolution_clock::now();
    int best = dynamicProgramming(ds, maxW, selectedItems);
    auto t1 = chrono::high_resolution_clock::now();

    double secs = chrono::duration<double>(t1 - t0).count();
    tc_clear_screen();
    cout << "[Dynamic Programming]\n"
         << "  Max Profit = " << best << "\n"
         << "  Time = " << secs << " s\n"
         << "  Items Used:\n ";
         
    for (auto it = selectedItems.rbegin(); it != selectedItems.rend(); ++it) {
        const auto& item = *it;
        cout << " " << item->getId()
             << ", " << item->getWeight()
             << ", " << item->getProfit() << "\n";
    }

    logResultToFile("Dynamic Programming", best, secs, selectedItems);
    if (all) logToCSV("Dynamic", best, secs, pallets);
    cout << "Press Enter to continue...";
    getchar();
}

void Menu::runILP(bool all) {
    int pallets, maxW;
    DataStruct ds;
    if (!loadData(pallets, maxW, ds)) return;

    int maxProfit = 0;
    std::vector<const Item*> selectedItems;
    auto t0 = chrono::high_resolution_clock::now();
    ilp(ds, maxW, maxProfit, selectedItems);
    auto t1 = chrono::high_resolution_clock::now();

    double secs = chrono::duration<double>(t1 - t0).count();
    tc_clear_screen();
    cout << "[ILP Algorithm]" <<  "\n"
         << "  Max Profit: "  << maxProfit  << "\n"
         << "  Time = " << secs << " s\n"
         << "  Items Used:\n ";
    for (auto item : selectedItems) {
        cout << " " << item->getId()
            << ", " << item->getWeight()
            << ", " << item->getProfit() << "\n";
    }

    logResultToFile("ILP", maxProfit, secs, selectedItems);
    cout << "Press Enter to return...";
    if (all) logToCSV("ILP", maxProfit, secs, pallets);
    getchar();
}

void Menu::runAllAlgorithms() {
    std::ofstream out("results.txt", std::ios::app);
    if (!out.is_open()) {
        std::cout << "Error: could not open results.txt\n";
        return;
    }
    out << "[ RUN ALL ALGORITHMS ]\n\n";
    out.close();

    runBruteForce(true);
    runBacktracking(true);
    runDynamicProgramming(true);
    runApproximate(true);
    runILP(true);

    // Run the Python script to generate the graph
    system("python3 ../benchmarks/tograph.py");
}


//Auxiliary Functions

void Menu::processArrowKeyInput(int& index, int maxIndex) const {
    getchar(); // Skip the '[' character
    switch (getchar()) {
        case 'A': // Arrow up
            index = (index > 0) ? index - 1 : maxIndex-1;
            break;
        case 'B': // Arrow down
            index = (index + 1) % maxIndex ;
            break;
        default:
            break;
    }
}

bool Menu::loadData(int &palletCount, int &maxW, DataStruct &ds) {
    std::ifstream tf(truckFile_), pf(palletFile_);
    if (!tf.is_open()) {
        tc_clear_screen();
        std::cerr << TC_RED <<"Error: cannot open truck file " << truckFile_ << "\n" << TC_NRM;
        std::cout << "Press Enter to continue...";
        getchar();
        return false;
    }
    if (!pf.is_open()) {
        tc_clear_screen();
        std::cerr << TC_RED <<"Error: cannot open pallet file " << palletFile_ << "\n" << TC_NRM;
        std::cout << "Press Enter to continue...";
        getchar();
        return false;
    }
    tf.close(); pf.close();

    try {
        DataStruct::getTruckAndPallets(truckFile_, palletCount, maxW);
        ds.initialize(palletFile_);
    } catch (const std::exception &e) {
        tc_clear_screen();
        std::cerr << TC_RED <<"Loading error: " << e.what() << "\n" << TC_NRM;
        std::cout << "Press Enter to continue...";
        getchar();
        return false;
    }
    return true;
}

void Menu::logResultToFile(const std::string& algorithmName, int bestProfit, double duration, const std::vector<const Item*>& items) const {
    std::ofstream out("../results.txt", std::ios::app);
    if (!out.is_open()) { std::cout << "Error: could not open results.txt\n"; ;return;}

    out << "[" << algorithmName << "]\n"
        << "Dataset:\n"
        << "  Truck file: " << truckFile_ << "\n"
        << "  Pallet file: " << palletFile_ << "\n"
        << "Max Profit = " << bestProfit << "\n"
        << "Time = " << duration << " s\n"
        << "Items Used:\n";
    for (const auto& item : items) {
        out << "" << item->getId()
            << ", " << item->getWeight()
            << ", " << item->getProfit() << "\n";
    }
    out << "\n";
}

void Menu::logToCSV(const std::string& algorithmName, int bestProfit, double duration, int palletCount) const {
    std::ofstream out("../benchmarks/bmarks.csv", std::ios::app);
    if (!out.is_open()) { std::cout << "Error: could not open bmarks.csv\n"; ;return;}

    out << algorithmName << ","
        << bestProfit << ","
        << duration << ","
        << palletCount << ","
        << truckFile_ << "," << palletFile_ << "\n";

    out.close(); // Make sure to close the file before running the Python script
}