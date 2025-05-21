#ifndef ITEM_H
#define ITEM_H

/**
 * @class Item
 * @brief A class representing an item with id, weight, and profit attributes.
 *
 * This class is used to model the pallets that can be selected as part of the solution
 * to our knapsack problem, where each one has a weight and profit value.
 */
class Item {
public:
    /**
     * @brief Constructor for the Item class.
     * @param id The unique identifier for the item.
     * @param weight The weight of the item.
     * @param profit The profit value of the item.
     */
    Item(int id, int weight, int profit);
    
    /**
     * @brief Get the ID of the item.
     * @return The item's ID.
     */
    int getId() const;
    
    /**
     * @brief Get the weight of the item.
     * @return The item's weight.
     */
    int getWeight() const;
    
    /**
     * @brief Get the profit value of the item.
     * @return The item's profit.
     */
    int getProfit() const;
    
    /**
     * @brief Calculate the weight-to-profit ratio of the item.
     * @return The weight divided by profit.
     */
    int getWeightByProfit() const;
    
    /**
     * @brief Print the item's details to standard output.
     */
    void print() const;

private:
    int id;      ///< The unique identifier of the item.
    int weight;  ///< The weight of the item.
    int profit;  ///< The profit value of the item.
};

#endif //ITEM_H