#ifndef BUBBLESORT_HPP
#define BUBBLESORT_HPP

class BubbleSort
{
    private:
        int currentSize;
        int numOfElements;
        int * array;
    public:
        BubbleSort(int numberofindexs);
        void insert(int key);
        void display();
        bool search(int key);
        void sort();
        void swap(int &smallElement,int &BigElement);

};
#endif