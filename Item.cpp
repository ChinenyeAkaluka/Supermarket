#include <stdio.h>
#include <iostream>
#include <string>

using namespace std

//Class Item
class Item
{
private:
    string type;    //type of item purchased
    int scanTime;    //the time take to scan this item
    
public:
    Item();                             //null constructor
    Item(string type, int scanTime);    //parametised constructor
    Item(const Item& myItem);           //copy constructor
    ~Item();                            //destructor
    int getScanTime() const;           //accessor
    
    
};

//Implementation

//constructor
Item::Item(string type, int scanTime)
{
    this->type = type;
    this->scanTime = scanTime;
}

//copy constructor
Item::Item(const Item& myItem)
{
    type = myItem.type;
    scanTime = myItem.scanTime;
}

//accessor
int getScanTime() const;
{
    return scanTime;
}

//Destructor
Item::~Item()
{
    //Only primitive types in Item, so there's nothing to do. We'll print a message.
    cout << "Deleting Item"<<endl;
}

