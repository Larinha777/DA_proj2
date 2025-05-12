#ifndef ITEM_H
#define ITEM_H

class Item {
public:
    Item(int id, int weight, int profit);
    int getId() const;
    int getWeight() const;
    int getProfit() const;
    int getWeightByProfit() const;


private:
    int id;
    int weight;
    int profit;
};


#endif //ITEM_H
