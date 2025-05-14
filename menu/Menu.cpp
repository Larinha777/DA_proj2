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

    // Confirmation
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
        // futuro adicionar os algoritmos da lara e do vasco
        "0. Return "
      };
    int choice = selectFromList(algos, "Select algorithm to run:");
    switch (choice) {
        case 0: runBruteForce();   break;
        case 1: runBacktracking(); break;
            // futuro adicionar os algoritmos da lara e do vasco
        default: break;
    }
}


//Algorithems

void Menu::runBruteForce() {
    int pallets, maxW;
    DataStruct ds;
    if (!loadData(pallets, maxW, ds)) return;

    auto t0 = chrono::high_resolution_clock::now();
    int best = bruteForce(ds, maxW);
    auto t1 = chrono::high_resolution_clock::now();

    double secs = chrono::duration<double>(t1 - t0).count();
    tc_clear_screen();
    cout << "[Brute-Force]\n"
         << "  Max Profit = " << best << "\n"
         << "  Time        = " << secs << " s\n\n"
         << "Press Enter to continue...";
    getchar();
}

void Menu::runBacktracking() {
    int pallets, maxW;
    DataStruct ds;
    if (!loadData(pallets, maxW, ds))return;

    auto t0 = chrono::high_resolution_clock::now();
    int best = backtracking(ds, maxW);
    auto t1 = chrono::high_resolution_clock::now();

    double secs = chrono::duration<double>(t1 - t0).count();
    tc_clear_screen();
    cout << "[Backtracking]\n"
         << "  Max Profit = " << best << "\n"
         << "  Time        = " << secs << " s\n\n"
         << "Press Enter to continue...";
    getchar();
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





