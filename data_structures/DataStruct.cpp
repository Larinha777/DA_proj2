#include "DataStruct.h"
#include <algorithm>
#include <fstream>
#include <sstream>

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

void DataStruct::getTruckAndPallets(const std::string& trucks, int &pallets, int &maxWeight) {
    std::ifstream truckFile(trucks);
    if (!truckFile.is_open()) {
        throw std::runtime_error("Failed to open trucks file: " + trucks);
    }

    std::string line;
    std::getline(truckFile, line); // Skip header line

    std::getline(truckFile, line);
    std::stringstream ss(line);
    std::string capacityStr, palletsStr;
    if (std::getline(ss, capacityStr, ',') && std::getline(ss, palletsStr)) {
        maxWeight = std::stoi(capacityStr);
        pallets = std::stoi(palletsStr);
    }
    truckFile.close();
}


void DataStruct::initialize(const std::string& pallets) {
    std::ifstream palletFile(pallets);
    if (!palletFile.is_open()) {
        throw std::runtime_error("Failed to open pallets file: " + pallets);
    }

    std::string line;

    std::getline(palletFile, line); // Skip header line
    while (std::getline(palletFile, line)) {
        if (line.empty())
            continue;
        std::stringstream ss(line);
        std::string idStr, weightStr, profitStr;
        if (std::getline(ss, idStr, ',') &&
            std::getline(ss, weightStr, ',') &&
            std::getline(ss, profitStr, ',')) {
            int idInt = std::stoi(idStr);
            int weightInt = std::stoi(weightStr);
            int profitInt = std::stoi(profitStr);

            this->addItem(new Item(idInt, weightInt, profitInt));
        }
    }
    palletFile.close();
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
