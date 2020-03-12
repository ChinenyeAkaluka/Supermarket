#include <stdio.h>
#include <iostream>
#include <string>
#include <fstream> //for opening an input stream (to read a file)
#include <sstream> //for using stringstream --> a way to split a string

using namespace std;

//==========================================================================================================
//Class Arrival
class Arrival
{
private:
    int customerId;
    string itemList;
    int arrivalTime;
    int totalScanTime;
    
public:
    Arrival();                             //null constructor
    Arrival(int ID, int ATime, int TSTime, string list);    //parametised constructor
    Arrival(const Arrival& Arrival);           //copy constructor
    ~Arrival();                            //destructor
    void print();
    
};

//===========================================================================================================


//Implementation for Arrival class
//constructor
Arrival::Arrival(int ID, int ATime, int TSTime, string list)
{
    customerId = ID;
    arrivalTime = ATime;
    itemList = list;
    totalScanTime = TSTime;
    
}

//copy constructor
Arrival::Arrival(const Arrival& myArrival)
{
    customerId = myArrival.customerId;
    arrivalTime = myArrival.arrivalTime;
    itemList = myArrival.itemList;
    totalScanTime = myArrival.totalScanTime;
    
}

//Destructor
Arrival::~Arrival()
{
    cout<<"deleting this arrival"<<endl;
}

void Arrival::print()
{
    cout<<"Time " <<arrivalTime<<" : Customer "<< customerId<< " arrives. "<<endl; //itemList<<" ServiceTime "<<totalScanTime<<endl;
    
}
//========================================================================================================

int main(int argCount, char* argv[])
{
    //This is just to show you the arguments. Notice that the name of the program is always the first argument.
    for (int i = 0; i < argCount; i++)
        cout<<"Arg "<<i<<" is: "<<argv[i]<<endl;
    
    //It's always good to check the number of arguments and output an error message
    //if you don't get the number of arguments you're expecting:
    if(argCount != 3) //the name of the program counts as the first arguments
    {
        cout<<"Error"<<endl;
        return 0; //exiting the program
    }
    
    string filename = argv[1];
    
    string option = argv[2]; //In this case option 1 will process the file, 0 will exit the program.
    
    if(option == "0") //even if we expect a number, there is no need to convert it to an int
        return 0;
    
    else if(option == "1")  //std::string can be compared safely using == (does not work for c-strings though)
    {
        //To open the file stream
        ifstream myFile;
        myFile.open(filename);
        string line;
         //int customerid = 1;
        //To read one line at a time:
        while(getline(myFile, line)) //while will stop when reaching EOF
        {
            //building a stringstream on the line string will allow us to parse it...
            istringstream iss(line);  //... this will be especially useful when you don't know in advance how many tokens you will have in your string
            string token; //we will get one token at a time from the stringstream
            
            
            while(getline(iss, token, '\0'))  //this will return one token at a time, using a whitespace as a separator
            {
                cout<<token<<endl;
                string blah = " ";
                int arrivaltime;
                int scantime = 0;
                string items = " ";
                int customerid = 1;
                Arrival* newArrival;
                int count = 0;
                string lastitem;
               while(getline(token, blah, ' '))
               {
                   
                if(count == 0)
                {
                    arrivaltime = stoi(token);
                }
                if( (count == 3) || (count == 5) || (count == 7) || (count == 9))
                {
                    items += token;
                    items += " ";
                    lastitem = token;
                }
                if( (count == 4) || (count == 6) || (count == 8) || (count == 10) )
                {
                    items += token;
                    items += " ";
                    if(lastitem.compare("BIG") == 0)
                    {
                        scantime += stoi(token)*2;
                    }
                    if(lastitem.compare("SMALL") == 0)
                    {
                        scantime += stoi(token);
                    }
                    if(lastitem.compare("FORV") == 0)
                    {
                        scantime += stoi(token)*4;
                    }
                    if(lastitem.compare("COUPON") == 0)
                    {
                        scantime += stoi(token)*5;
                    }
                }
                 //blah = strtok(NULL, " ");
                 count++;
               }
                
               
            }
           // newArrival = new Arrival(customerid, arrivaltime, scantime, items);
            //newArrival->print();
           // customerid++;
            cout<<" "<<endl;
        }
        
        //Closing the file stream
        myFile.close();
    }
    
    return 0;
}
