#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "../data_structures/DataStruct.h"

/**
 * @class Menu
 * @brief The Menu class provides a text-based user interface for the Truck Pallet Packing application.
 * 
 * This class manages the interactive console menu that allows users to:
 * - Select and load datasets
 * - Run different algorithms for solving the 0/1 Knapsack problem
 * - View and compare algorithm results
 */
class Menu {
    int selectedItemIndex;    ///< The index of the currently selected menu item.
    std::string currentColor; ///< The current text color code used for highlighting selections.
    std::vector<std::string> items; ///< List of main menu options.
    std::string truckFile_;   ///< Path to the truck configuration file.
    std::string palletFile_;  ///< Path to the pallet configuration file.

    /**
     * @brief Displays a list of options and allows the user to select one.
     * 
     * @param options List of options to display
     * @param prompt Text to display above the list of options
     * @param initialIndex The initially selected option index (default: 0)
     * @return int The index of the selected option
     */
    int selectFromList(const std::vector<std::string>& options, const std::string& prompt, int initialIndex = 0);
    
    /**
     * @brief Handles the selected option from the main menu.
     */
    void handleSelection();

    /**
     * @brief Displays the dataset selection menu and loads the selected dataset.
     */
    void changeDataSet();
    
    /**
     * @brief Displays the algorithm selection menu.
     */
    void runAlgorithmMenu();

    /**
     * @brief Runs the Brute Force algorithm on the current dataset.
     *
     * @param all Flag to either add to CSV or not.
     */
    void runBruteForce(bool all);
    
    /**
     * @brief Runs the Backtracking algorithm on the current dataset.
     *
     * @param all Flag to either add to CSV or not.
     */
    void runBacktracking(bool all);
    
    /**
     * @brief Runs the Approximate algorithm on the current dataset.
     *
     *  @param all Flag to either add to CSV or not.
     */
    void runApproximate(bool all);
    
    /**
     * @brief Runs all the implemented algorithms on the current dataset.
     *
     */
    void runAllAlgorithms();

    void runDynamicProgramming();

    /**
     * @brief Runs the Dynamic Programming algorithm on the current dataset.
     * Also runs dedicated Python script for further algorithm comparison.
     *
     *  @param all Flag to either add to CSV or not.
     */
    void runDynamicProgramming(bool all);

    /**
     * @brief Runs the ILP algorithm on the current dataset.
     *
     *  @param all Flag to either add to CSV or not.
     */
    void runILP(bool all);

    /**
     * @brief Processes arrow key input for menu navigation.
     * 
     * @param index Reference to the current selection index
     * @param maxIndex The maximum valid index value
     */
    void processArrowKeyInput(int& index, int maxIndex) const;
    
    /**
     * @brief Loads data from the selected files.
     * 
     * @param palletCount [out] Number of pallets loaded
     * @param maxWeight [out] Maximum weight capacity of the truck
     * @param ds [out] Data structure to be populated with items
     * @return bool True if data loading was successful, False otherwise
     */
    bool loadData(int &palletCount, int &maxWeight, DataStruct &ds);
    
    /**
     * @brief Logs algorithm results to the results.txt file.
     * 
     * @param algorithmName Name of the algorithm
     * @param bestProfit Best profit achieved by the algorithm
     * @param duration Execution time in seconds
     * @param items List of selected items in the solution
     */
    void logResultToFile(const std::string& algorithmName, int bestProfit, double duration, const std::vector<const Item*>& items) const;

    /**
     * @brief Logs a single algorithm's result in CSV file when all algorithms are run
     * for further analysis.
     *
     * @param algorithmName Name of the algorithm
     * @param bestProfit Best profit achieved by the algorithm
     * @param duration Execution time in seconds
     * @param palletCount Number of pallets
     */
    void logToCSV(const std::string &algorithmName, int bestProfit, double duration, int palletCount) const;

public:
    /**
     * @brief Constructs a new Menu object.
     * 
     * Initializes the menu with default values and menu items.
     */
    Menu();
    
    /**
     * @brief Starts the menu interface.
     * 
     * Sets up the terminal for raw mode, displays the menu,
     * and handles user input until the program is exited.
     */
    void run();
};

#endif // MENU_H