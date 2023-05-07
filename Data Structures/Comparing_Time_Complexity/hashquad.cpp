#include <iostream>
#include "hashquad.hpp"
#include <cmath>
using namespace std;

HashTable::HashTable(int size)
{
    tableSize=size;
    table= new int[tableSize];
}

unsigned int HashTable::hashFunction(int key)
{
    return (key%tableSize);
}

void HashTable::insert(int key)
{
    int i = hashFunction(key);
    int index=i;
    if(table[index]==0)
    {
        table[index]=key;
        return;
    }
    else
    {
        int a=1;
        while(table[index]!=0)
        {
            index=i+pow(a,2);
            a++;
            numOfCollisions++;
            if(index>tableSize-1)
            {
                index=index%tableSize;
            }
        }
        table[index]=key;
        return;
    }
}

void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++) {
        cout << i <<"|| ";
        if(table[i]!=0)
        {
            cout<< table[i];
        }
        cout << "\n";
    }
}

int HashTable::getNumOfCollision()
{
    return numOfCollisions;
}

bool HashTable::search(int key)
{
    int i = hashFunction(key);
    if(table[i]==key)
    {
        return true;
    }
    else
    {
        int a=1;
        int index=i;
        while(table[index]!=key)
        {
            index=i+pow(a,2);
            a++;
            if(index>tableSize-1)
            {
                index=index%tableSize;
            }
            if(table[index]==0)//not found
            {
                return false;
            }
        }
        return true;
    }
}