#include "Item.h"

#include <iostream>
#include <ostream>

Item::Item(const int id, const int weight, const int profit){
    this->id = id;
    this->weight = weight;
    this->profit = profit;
}

int Item::getId() const {
    return this->id;
}
int Item::getWeight() const {
    return weight;
}
int Item::getProfit() const {
    return profit;
}
int Item::getWeightByProfit() const{
    return weight/profit;
}
void Item::print() const {
    std::cout << "id:" << this->id << "\t weight:" << this->weight << "\t profit" << this->profit << std::endl;
}



