#include "DataStruct.h"
#include <algorithm>
DataStruct::DataStruct() {
    items = vector<Item*>();
}
DataStruct::~DataStruct() {
    for (Item* item : items) {
        delete item;
    }
}

void DataStruct::addItem(Item* i) {
    items.push_back(i);
}

void DataStruct::sortByProfit() {
    std::sort(items.begin(), items.end(), [](const Item* i, const Item* j) {
    return i->getProfit() > j->getProfit();
});

}
void DataStruct::sortByProfitPerWeight() {
    std::sort(items.begin(), items.end(), [](const Item* i, const Item* j) {
          return i->getWeightByProfit() > j->getWeightByProfit();
      });
}

void DataStruct::print() const {
    for (const Item* item : items) {
        item->print();
    }
}

std::vector<Item*>::const_iterator DataStruct::begin() const {
    return items.begin();
}
std::vector<Item*>::const_iterator DataStruct::end() const {
    return items.end();
}
