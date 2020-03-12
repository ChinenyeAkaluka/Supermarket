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
    string getString();
    int getCustomerId();
    int getArrivalTime();
    int getTotalScanTime();
    int getPrevScanTime();
    
};

//=================================================================================================
//Class StartService
class StartService: public Arrival
{
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
public:
    CompleteService();                             //null constructor
    CompleteService(int ID, int ATime, int TSTime, string list, int psTime, string lane);    //parametised constructor
    ~CompleteService();                            //destructor
    void print();
    
};

//===========================================================================================================
//Implementation for Arrival class
//constructor
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

string Arrival:: getString()
{
    return myLane;
}

int Arrival :: getCustomerId()
{
    return customerId;
}

int Arrival :: getArrivalTime()
{
    return arrivalTime;
}

int Arrival :: getTotalScanTime()
{
    return totalScanTime;
}

int Arrival :: getPrevScanTime()
{
    return prevScanTime;
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
    Arrival(ID, ATime, TSTime,  list,  psTime);
}

//Destructor
StartService::~StartService()
{
    cout<<"deleting this StartService"<<endl;
}

//print method
void StartService::print()
{
    cout<<"Time "<<getArrivalTime()+abs(getPrevScanTime()-getArrivalTime()) <<": Customer "<< getCustomerId()<< " begins service in "<<getString()<<endl;
}

//===========================================================================================================
//Implementation for CompleteService class
//constructor
CompleteService::CompleteService(int ID, int ATime, int TSTime, string list, int psTime, string lane)
{
    Arrival(ID, ATime, TSTime,  list,  psTime,  lane);
}

//Destructor
CompleteService::~CompleteService()
{
    cout<<"deleting this CompleteService"<<endl;
}

//print method
void CompleteService::print()
{
    cout<<"Time "<<getArrivalTime()+abs(getPrevScanTime()-getArrivalTime()) + getTotalScanTime() <<": Customer "<< getCustomerId()<< " completes service in "<<getString()<<" Arrival: "<<getArrivalTime()<<" Complete: "<<getArrivalTime()+abs(getPrevScanTime()-getArrivalTime()) + getTotalScanTime() <<" Wait: "<<
    abs(getPrevScanTime()-getArrivalTime())<<endl;
}



