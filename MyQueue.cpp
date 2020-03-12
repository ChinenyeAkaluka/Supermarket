#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

//Class Node
class Node
{
private:
    Arrival* anItem;                              //data contained in a node is an item
    Node* next;                               //connecting next node
    
public:
    Node(Arrival* myItem, Node* myNode);      //null constructor
    //Node(const Node& myNode);             //copy constructor
    ~Node();                            //destructor
    void setLink(Node* myNode);           //set data.
    Arrival* getData();                    //get item
    Node* getNext();                    //get connecting node
    void setData(Arrival* myItem);
    
};



//Class MyQueue
class MyQueue
{
private:
    Node* top;                              //the top of the linkedlist
    Node* last;
    
public:
    MyQueue();                             //null constructor
    MyQueue(const MyQueue& myMyQueue);           //copy constructor
    ~MyQueue();                            //destructor
    void addItem(Arrival anItem);
    Node* dequeue();
    bool isEmpty();
    
};

///////////////////////////////////////////////////////////////////////////////////////////////////////

//Implementation of class Node
//constructor
Node::Node(Arrival* myItem, Node* myNode)
{
    anItem=myItem;
    next=myNode;
}

//Destructor
Node::~Node()
{
    delete anItem;
}

void Node:: setLink(Node* myNode)
{
    next = myNode;
}

void Node:: setData(Arrival* myItem)
{
   anItem = myItem;
}

Node* Node::getNext()
{
    return next;
}

Arrival* Node::getData()
{
    return anItem;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////

//Implementation of class Linkedlist
//constructor
MyQueue::MyQueue()
{
    this->top = NULL;
    this->last = NULL;
}

//copy constructor
MyQueue::MyQueue(const MyQueue& myMyQueue)
{
    top = new Node(*myMyQueue.top);
    last = new Node(*myMyQueue.last);
}


void MyQueue::addItem(Arrival* anItem)
{
    Node * newNode;
    Node * curr = top;
    if(top == NULL)
    {
        newNode = new Node(anItem,last);
        top = newNode;
    }
    else if(top != NULL)
    {
        while(curr->getNext() != NULL)
        {
            curr = curr->getNext();
        }
        newNode = new Node(anItem,NULL);
        curr->setLink(newNode);
    }
     last = newNode;
    
}

Node* MyQueue :: dequeue()
{
    Node* curr = top;
    Node * thisnode = NULL;
    
    if(curr!=NULL)
    {
        thisnode = curr->getData();
        curr->setData() = NULL;
        this->top = curr->getNext();
        delete curr;
    }
    return thisnode;
}

bool MyQueue::isEmpty()
{
    return top == NULL;
}

//Destructor
MyQueue::~MyQueue()
{
    top = NULL;
    cout << "Deleting linkedlist"<<endl;
}
