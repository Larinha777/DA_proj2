#include "Item.h"

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



