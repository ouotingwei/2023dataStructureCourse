#include<iostream>
#include"dataStructure.h"

#define MAX_ITEM 7

using namespace std;

typedef struct tagQueue{
    int item[MAX_ITEM];
    int front = -1;
    int rear = -1;

}Queue;

int Enqueue(Queue *q, int x);
int Dequeue(Queue *q, int *xptr);

int main(){
    Queue Que;
    int temp;

    Enqueue(&Que, 10);
    Enqueue(&Que, 20);
    Enqueue(&Que, 30);

    Dequeue(&Que, &temp);
    cout<<temp<<endl;
    Dequeue(&Que, &temp);
    cout<<temp<<endl;
    Dequeue(&Que, &temp);
    cout<<temp<<endl;

    return 0;
}

int Enqueue(Queue *q, int x){  //put data x into queue q
    if( (q -> rear + 1) % MAX_ITEM == q -> front){
        return false;   //queue is full
    }

    q -> rear = (q -> rear + 1) % MAX_ITEM; //rear + 1 on clockwise
    q -> item [q -> rear] = x;

    return true;

}

int Dequeue(Queue *q, int *xptr){ //read a data to xptr fron queue
    if(q -> front == q -> rear){    //queue is empty
        return false;
    }

    q -> front = (q -> front + 1) % MAX_ITEM;
    *xptr = q -> item[q -> front];
    return true;

}