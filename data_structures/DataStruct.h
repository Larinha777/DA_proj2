#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include <vector>
#include <string>
#include "Item.h"

using namespace std;

/**
 * @class DataStruct
 * @brief A container class for managing a collection of Item objects
 * 
 * This class manages a vector of Item pointers and provides operations for
 * adding, sorting, and accessing items. It also includes functionality for
 * loading truck and pallet data from the csv files.
 */
class DataStruct {
    private:
        /**
         * @brief Vector containing pointers to Item objects
         */
        vector<Item*> items;
    public:
        /**
         * @brief Default constructor
         * 
         * Initializes an empty DataStruct with no items.
         */
        DataStruct();
        
        /**
         * @brief Destructor
         * 
         * Deletes all Item objects stored in the items vector.
         */
        ~DataStruct();

        /**
         * @brief Adds an Item to the collection
         * @param i Pointer to an Item object to add
         */
        void addItem(Item* i);
        
        /**
         * @brief Reads truck and pallet information from a file
         * @param trucks Filename containing truck information
         * @param pallets Reference to variable to store number of pallets
         * @param maxWeight Reference to variable to store maximum allowed weight
         * @throws std::runtime_error if the file cannot be opened
         */
        void static getTruckAndPallets(const std::string& trucks, int &pallets, int &maxWeight);
        
        /**
         * @brief Initializes the data structure from a pallets file
         * @param pallets Filename containing pallet information
         * @throws std::runtime_error if the file cannot be opened
         */
        void initialize(const std::string& pallets);

        /**
         * @brief Sorts items by profit in descending order
         */
        void sortByProfit();
        
        /**
         * @brief Sorts items by profit-to-weight ratio in descending order
         */
        void sortByProfitPerWeight();

        /**
         * @brief Prints all items in the collection
         */
        void print() const;
        
        /**
         * @brief Returns an iterator to the beginning of the items collection
         * @return Constant iterator to the first item
         */
        std::vector<Item*>::const_iterator begin() const;
        
        /**
         * @brief Returns an iterator to the end of the items collection
         * @return Constant iterator past the last item
         */
        std::vector<Item*>::const_iterator end() const;

        /**
         * @brief Gets the vector of Item pointers
         * @return Constant reference to the vector of Item pointers
         */
        const std::vector<Item*>& getItems() const;
};

#endif //DATASTRUCT_H