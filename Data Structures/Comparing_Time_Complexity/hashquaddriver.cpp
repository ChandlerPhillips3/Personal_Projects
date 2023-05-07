 #include <iostream>
 #include "hashquad.hpp"
 #include <fstream>
 #include <chrono>
//Use these for generating random numbers:
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
using namespace std;
using namespace std::chrono;

int main(int argc,char * argv[])
{
    high_resolution_clock::time_point startInsert;
    high_resolution_clock::time_point endInsert;
    duration<double> execTimeInsert;
    high_resolution_clock::time_point startSearch;
    high_resolution_clock::time_point endSearch;
    duration<double> execTimeSearch;
    int testData[10000];//holds data
    int testDataIndex=0;
    float insert[100];//holds insert time
    int numInsert=0;
    float search[100];//holds search time
    int numSearch=0;
    int randomNumbers[100];
    string line;
    int keyToAdd;
    int collisions[100];
    int collisionsIndex=0;
    int previousnumcollisions;
    HashTable Table(40009);
    ifstream file(argv[1]);
    if(!file.is_open())
    {
        cout<< "File didn't open properly"<<endl;
    }
    else
    {
        while(!file.eof())
        {
            getline(file, line, ',');
            keyToAdd=stoi(line);
            testData[testDataIndex]=keyToAdd;
            //cout<< "testData[" <<testDataIndex<<"]"<<testData[testDataIndex]<<endl;//Test case to make sure data was added to array correctly
            testDataIndex++;
        }
        int current=0;//current element we are on in testData
        int intervalof100=100;
        while(current<10000)
        {
            //start insert time here
            startInsert= high_resolution_clock::now();
            while(current<intervalof100)
            {
                Table.insert(testData[current]);
                current++;
            }
            //end insert time here
            endInsert= high_resolution_clock::now();
            execTimeInsert=duration_cast<nanoseconds>(endInsert-startInsert);
            float TimeInsert;
            TimeInsert=execTimeInsert.count()/100.0;
            //store insert time: 
            insert[numInsert]= TimeInsert;
            numInsert++;
            //generate 100 psudeo random numbers:
            for(int i=0;i<100;i++)
            {
                randomNumbers[i]=rand()%intervalof100;
            }
            //start time for search
            startSearch=high_resolution_clock::now();
            for(int i=0;i<100;i++)
            {
                Table.search(testData[randomNumbers[i]]);
            }
            //end time for search here
            endSearch=high_resolution_clock::now();
            execTimeSearch=duration_cast<nanoseconds>(endSearch-startSearch);
            float TimeSearch;
            TimeSearch=execTimeSearch.count()/100.0;
            //store search time:
            search[numSearch]= TimeSearch;
            numSearch++;
            //Collisions:
            int newNumberOfCollisions=Table.getNumOfCollision()-previousnumcollisions;
            collisions[collisionsIndex]=newNumberOfCollisions;
            collisionsIndex++;
            previousnumcollisions=Table.getNumOfCollision();
            intervalof100=intervalof100+100;
        }
        cout<< Table.getNumOfCollision()<<endl;
        cout<< current<< endl;
        //read data to files:
        ofstream myfile("insert_search_performance_hashQuad_dataSetA.csv");
        if(myfile.is_open())
        {
            myfile<<"Insert HashQuad"<<endl;
            for(int i=0;i<100;i++)
            {
                myfile<<insert[i]<<"\n";
            }
            myfile<<"Search HashQuad"<<endl;
            for(int i=0;i<100;i++)
            {
                myfile<<search[i]<<"\n";
            }
            myfile<<"HashQuad: Number of collisions"<<endl;
            for(int i=0;i<100;i++)
            {
                myfile<<collisions[i]<<"\n";
            }
        }
    }
    //Table.printTable();
}