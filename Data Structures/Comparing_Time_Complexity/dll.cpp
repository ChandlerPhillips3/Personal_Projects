#include "dll.hpp"
#include <iostream>
using namespace std;

Dll::Dll()
{
    head=NULL;
}

void Dll::Insert(int key)
{
    if(head==NULL)
    {
        head=new Node;
        head->key=key;
        head->next=NULL;
        head->prev=NULL;
    }
    else
    {
        Node * newNode=new Node;
        newNode->key=key;
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
    }
}

void Dll::Display()
{
    Node * crawler=head;
    while(crawler!=NULL)
    {
        cout<< crawler->key << endl;
        crawler=crawler->next;
    }
}

bool Dll::search(int key)
{
    Node * crawler=head;
    while(crawler!=NULL)
    {
        if(crawler->key==key)
        {
            return true;
        }
        crawler=crawler->next;
    }
    return false;
}