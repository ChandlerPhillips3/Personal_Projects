#ifndef DLL_H
#define DLL_H
#include <iostream>
using namespace std;

struct Node{
    int key;
    Node * next;
    Node * prev;
};

class Dll
{
    private:
        Node * head;
    public:
        Dll();
        void Insert(int key);
        void Display();
        bool search(int key);
};

#endif // DLL_H