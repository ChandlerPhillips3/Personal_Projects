#include <iostream>
#include "bubblesort.hpp"
using namespace std;

BubbleSort::BubbleSort(int numberofindexs)
{
    array=new int[numberofindexs];
    numOfElements=0;
}

void BubbleSort::insert(int key)
{
    array[numOfElements]=key;
    numOfElements++;
}

void BubbleSort::display()
{
    for(int i=0;i<numOfElements;i++)
    {
        cout<< "array["<<i<<"]"<<array[i]<<endl;
    }
}

bool BubbleSort::search(int key)
{
    for(int i=0; i<numOfElements;i++)
    {
        if(array[i]==key)
        {
            return true;
        }
    }
    return false;
}

void BubbleSort::sort()
{
    for(int i=0;i<numOfElements-1;i++)
    {
        for(int j=0;j<numOfElements-i-1;j++)
        {
            if(array[j]>array[j+1])
            {
                swap(array[j],array[j+1]);
            }
        }
    }
}

void BubbleSort::swap(int &smallElement,int &BigElement)
{
    int holder=smallElement;
    smallElement=BigElement;
    BigElement=holder;
}
