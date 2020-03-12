#include <stdio.h>
#include <iostream>
#include <string>
#include <cmath>


using namespace std;

//=================================================================================================
//Class CheckOut
class CheckOut    //abstract class to group the two checkout systems
{
public:
    virtual void print() = 0;
    ~CheckOut();
    
};

//=================================================================================================
//Class ExpressLane
//Has two lanes : express for <= 12 items and regular for > 12 items
class ExpressLane: public CheckOut
{
private:
    MyQueue * Express;
    MyQueue * Regular;
    MyQueue * WaitingLine;
    
public:
    ExpressLane();                             //null constructor
    ~ExpressLane();                            //destructor
    void print();
    
};


//=================================================================================================
//Class OneWaitingLine
//Has two lanes for all number of items
class OneWaitingLine: public CheckOut
{
private:
    MyQueue * Express;
    MyQueue * Regular;
    MyQueue * WaitingLine;
    
public:
    OneWaitingLine();                             //null constructor
    ~OneWaitingLine();                            //destructor
    void print();
    
};

//================================================================================================
//Implementation for CheckOut class
//constructor
CheckOut::~CheckOut(){}

//================================================================================================
//Implementation for ExpressLane class
//constructor
ExpressLane::ExpressLane()
{
    Express = new MyQueue();
    Regular = new MyQueue();
    WaitingLine = new MyQueue();
}

//Destructor
ExpressLane::~ExpressLane()
{
    delete Express;
    delete Regular;
    delete WaitingLine;
    cout<<"deleting this ExpressLane"<<endl;
}

//print method
void ExpressLane::print()
{
    cout<<"printing..."<<endl;
}

//================================================================================================
//Implementation for OneWaitingLine class
//constructor
OneWaitingLine::OneWaitingLine()
{
    Express = new MyQueue();
    Regular = new MyQueue();
    WaitingLine = new MyQueue();
}

//Destructor
OneWaitingLine::~OneWaitingLine()
{
    delete Express;
    delete Regular;
    delete WaitingLine;
    cout<<"deleting this ExpressLane"<<endl;
}

//print method
void OneWaitingLine::print()
{
    cout<<"printing..."<<endl;
}


