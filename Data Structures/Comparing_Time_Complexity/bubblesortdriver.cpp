#include <iostream>
#include "bubblesort.hpp"
#include <fstream>
#include <chrono>
using namespace std;
using namespace std::chrono;


int main(int argc,char * argv[])
{
    high_resolution_clock::time_point startSort;
    high_resolution_clock::time_point endSort;
    duration<double> execTimeSort;
    int testData[10000];//holds data
    int testDataIndex=0;
    float sort[100];
    int numsort=0;
    string line;
    int keyToAdd;
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
            testDataIndex++;
        }
        int size=100;
        while(size<=10000)
        {
            BubbleSort data(size);
            for(int i=0;i<size;i++)
            {
                data.insert(testData[i]);
            }
            startSort= high_resolution_clock::now();
            data.sort();
            endSort= high_resolution_clock::now();
            execTimeSort=duration_cast<nanoseconds>(endSort-startSort);
            float TimeSort=execTimeSort.count()/100.0;
            sort[numsort]=TimeSort;
            numsort++;
            size=size+100;
        }
        cout<< numsort<<endl;
        ofstream myfile("sort_performance_bubbleSort_dataSetA.csv");
        if(myfile.is_open())
        {
            myfile<<"Bubble Sort"<<endl;
            for(int i=0;i<100;i++)
            {
                myfile<<sort[i]<<"\n";
            }
        }

    }
    /*
    array.display();
    array.sort();
    array.display();*/
    /*for(int i=0;i<NumOfCSV;i++)
    {
        cout << "TestData["<< i << "]= " << TestData[i]<<endl;
    }*/
}