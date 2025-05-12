#ifndef DATASTRUCT_H
#define DATASTRUCT_H
#include <vector>
#include "Item.h"

using namespace std;


class DataStruct {
    private:
        vector<Item*> items;
    public:
        DataStruct();
        ~DataStruct();
        void addItem(Item* i);
        void sortByProfit();
        void sortByProfitPerWeight();
        void print() const;
        std::vector<Item*>::const_iterator begin() const;
        std::vector<Item*>::const_iterator end() const;
};



#endif //DATASTRUCT_H
