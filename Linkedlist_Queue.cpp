/*
Make a queue using Linked list
Benifit: If we will make a queue throug arr it can take more storage, Example: If we assign array of size 100 and use only 20 so the rest 80 size will take the memory useless. But in linked list we can use only the size we need. So it is more efficient.
*/

#include<iostream>
using namespace std;
 class node
 {
    public:
    int data;
    node *next;

    node(int val)
    {
        data=val;
        next=NULL;

    }
 };
int main()
{

 return 0;
}