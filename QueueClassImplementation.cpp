#include<iostream>
using namespace std;
#define MAXSIZE 10
 
void init_Queue(struct Queue *obj)
{
 obj->front=0;
 obj->rear=0;
}
bool isfull(struct Queue *obj)
{
    if (obj->rear==MAXSIZE)
    {
        return true;
    }
    else
    {
        return false;
    }
    
    
}
bool enqueue(struct Queue *obj, int val){
 if (!isfull(obj))
 {
     obj->arr[obj->rear]=val;
    (obj->rear++)%MAXSIZE;
    return true;
 }
 else
 {
    return false;
 }
 
   
}

struct Queue
{
   
    int arr[MAXSIZE];
    int  front, rear;

};

int main(){
struct Queue obj;

init_Queue(&obj);
enqueue(&obj,10);
enqueue(&obj,20);
enqueue(&obj,30);
enqueue(&obj,40);
enqueue(&obj,50);

 return 0;
}