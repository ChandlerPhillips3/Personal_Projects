#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <iostream>
using namespace std;

class HashTable
{
    private:
        int tableSize;
        int * table;
        int numOfCollisions=0;
    public:
        HashTable(int bsize);  // Constructor

        // inserts a key into hash table
        void insert(int key);

        // hash function to map values to key
        unsigned int hashFunction(int key);
        void printTable();
        int getNumOfCollision();
        bool search(int key);

};
#endif