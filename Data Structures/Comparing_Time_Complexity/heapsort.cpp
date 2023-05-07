#include <iostream>
#include "heapsort.hpp"


Heap::Heap(int size)
{
    heaptree= new int [size];
    numOfElements=0;
}

int Heap::IndexElement(int index)
{
    return heaptree[index];
}

int Heap::parent(int index)
{
    return (index-1)/2;
}

int Heap::leftChild(int index)
{
    return 2*index+1;
}

int Heap::rightChild(int index)
{
    return 2*index+2;
}


void Heap::Insert(int key)
{
    numOfElements++;
    int index=numOfElements-1;
    heaptree[index]=key;
    while(index!=0 && heaptree[parent(index)] > heaptree[index])
    {
        swap(heaptree[index],heaptree[parent(index)]);
        index=parent(index);
    }
}

void Heap::swap(int &smallElement,int &BigElement)
{
    int holder=smallElement;
    smallElement=BigElement;
    BigElement=holder;
}


void Heap::minheapify(int key)
{
    int lefty = leftChild(key);//gets index of what the left child would be in heap
    int righty = rightChild(key);//gets index of what the right child would be in heap
    int smallest=key;//holds key
    if(lefty < numOfElements && heaptree[lefty] <heaptree[smallest])//if left child is less then number of elements and the value is smaller then the current
    {
        smallest=lefty;//it is now the smallest
    }
    if(righty < numOfElements && heaptree[righty] <heaptree[smallest])//right child smaller
    {
        smallest=righty;//now hold to swap
    }
    if(smallest!=key)//smallest is not the key
    {
        swap(heaptree[key],heaptree[smallest]);//swap the two call again
        minheapify(smallest);
    }
}

void Heap::display()//prints heap
{
    for(int i=0;i<numOfElements;i++)
    {
        cout<< "heap["<<i<<"]"<<heaptree[i]<<endl;
    }
}

bool Heap::search(int key)//returns true if it finds the key
{
    for(int i=0; i<numOfElements;i++)
    {
        if(heaptree[i]==key)
        {
            return true;
        }
    }
    return false;
}

void Heap::peek()
{
    cout<<heaptree[0]<<endl;//prints the head of the Heap
}