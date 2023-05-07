#include <iostream>
#include "heapsort.hpp"
#include <string>
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
            Heap data(size);
            for(int i=0;i<size;i++)
            {
                data.Insert(testData[i]);
            }
            startSort= high_resolution_clock::now();
            for(int i=0;i<size;i++)
            {
                data.minheapify(data.IndexElement(i));
            }
            endSort= high_resolution_clock::now();
            execTimeSort=duration_cast<nanoseconds>(endSort-startSort);
            float TimeSort=execTimeSort.count()/100.0;
            sort[numsort]=TimeSort;
            numsort++;
            size=size+100;
            //data.peek();//used to test what the smallest value currently in the heap is
        }
        //cout<< numsort<<endl;//used to make sure we had 100 indexes stored inside sort array
        ofstream myfile("sort_performance_heap_dataSetA.csv");
        if(myfile.is_open())
        {
            myfile<<"Heap Sort"<<endl;
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