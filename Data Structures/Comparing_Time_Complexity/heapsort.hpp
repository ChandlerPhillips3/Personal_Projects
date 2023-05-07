#ifndef HEAP_H
#define HEAP_H
#include <iostream>
using namespace std;

class Heap
{
    private:
        int * heaptree;
        int numOfElements;
        int capcity;
        int size;
    public:
        Heap(int size);
        int IndexElement(int index);
        void Insert(int key);
        bool search(int key);
        void display();
        int parent(int index);
        int leftChild(int index);
        int rightChild(int index);
        void swap(int &smallElement,int &BigElement);
        void minheapify(int key);
        void peek();
};

#endif