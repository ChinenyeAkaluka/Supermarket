#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

//=================================================================================================
//Class Event
class Event
{
public:
    virtual void print() = 0;
    ~Event();
    
};

//=================================================================================================
//Class Arrival
class Arrival: public Event
{
private:
    int customerId;
    string itemList;
    int arrivalTime;
    int totalScanTime;
    int prevScanTime;
    string myLane;
    
public:
    Arrival();                             //null constructor
    Arrival(int ID, int ATime, int TSTime, string list, int psTime, string lane);    //parametised constructor
    ~Arrival();                            //destructor
    void print();
    
};

//=================================================================================================
//Class StartService
class StartService: public Arrival
{
private:
    int customerId;
    string itemList;
    int arrivalTime;
    int totalScanTime;
    int prevScanTime;
    string myLane;
public:
    StartService();                             //null constructor
    StartService(int ID, int ATime, int TSTime, string list, int psTime, string lane);    //parametised constructor
    ~StartService();                            //destructor
    void print();
    
};

//==================================================================================================

//Class CompleteService
class CompleteService: public Arrival
{
private:
    int customerId;
    string itemList;
    int arrivalTime;
    int totalScanTime;
    int prevScanTime;
    string myLane;
public:
    CompleteService();                             //null constructor
    CompleteService(int ID, int ATime, int TSTime, string list, int psTime, string lane);    //parametised constructor
    ~CompleteService();                            //destructor
    void print();
    
};

//================================================================================================
//Implementation for Event class
//constructor
Event::~Event(){}

//================================================================================================
//Implementation for Arrival class
//constructor
Arrival::Arrival()
{
    cout<<"creating an Arrival"<<endl;
}

Arrival::Arrival(int ID, int ATime, int TSTime, string list, int psTime, string lane)
{
    customerId = ID;
    arrivalTime = ATime;
    itemList = list;
    totalScanTime = TSTime;
    prevScanTime = psTime;
    myLane = lane;
    
}

//Destructor
Arrival::~Arrival()
{
    cout<<"deleting this arrival"<<endl;
}

//print method
void Arrival::print()
{
    cout<<"Time "<<arrivalTime <<": Customer "<< customerId<< " arrives "<<itemList<<" "<<totalScanTime<<endl;
}

//===========================================================================================================
//Implementation for StartService class
//constructor
StartService::StartService(int ID, int ATime, int TSTime, string list, int psTime,string lane)
{
    Arrival();
    customerId = ID;
    arrivalTime = ATime;
    itemList = list;
    totalScanTime = TSTime;
    prevScanTime = psTime;
    myLane = lane;
}

//Destructor
StartService::~StartService()
{
    cout<<"deleting this StartService"<<endl;
}

//print method
void StartService::print()
{
    cout<<"Time "<<arrivalTime+abs(prevScanTime-arrivalTime) <<": Customer "<< customerId<< " begins service in "<<myLane<<endl;
}

//===========================================================================================================
//Implementation for CompleteService class
//constructor
CompleteService::CompleteService(int ID, int ATime, int TSTime, string list, int psTime, string lane)
{
    Arrival();
    customerId = ID;
    arrivalTime = ATime;
    itemList = list;
    totalScanTime = TSTime;
    prevScanTime = psTime;
    myLane = lane;}

//Destructor
CompleteService::~CompleteService()
{
    cout<<"deleting this CompleteService"<<endl;
}

//print method
void CompleteService::print()
{
    cout<<"Time "<<arrivalTime+abs(prevScanTime-arrivalTime) + totalScanTime <<": Customer "<< customerId<< " completes service in "<<myLane<<" Arrival: "<<arrivalTime<<" Complete: "<<arrivalTime+abs(prevScanTime-arrivalTime) + totalScanTime <<" Wait: "<<
    abs(prevScanTime-arrivalTime)<<endl;
}



