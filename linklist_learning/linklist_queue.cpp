#include<iostream>
#define QUE_SIZE 10

using namespace std;

typedef struct queue *queue_pointer;
typedef struct queue{
    int data;
    queue_pointer link;
};
queue_pointer front[QUE_SIZE], rear[QUE_SIZE];

void addq(queue_pointer *front, queue_pointer *rear, int data){
    /*add an data to the rear of the queue*/
    queue_pointer temp = new queue;
    if(isFull(temp) == true){
        return false;
    }
    temp -> data = data;
    temp -> link = NULL;
    if(*front != NULL){
        rear -> link = temp;
    }else{
        *rear = temp;
    }
}

int deletreq(queue_pointer *front){
    /*delete data from queue*/
    queue_pointer temp = *front;
    int data;
    if(isEmpty(*front) == true){
        return false;
    }
    data = temp -> data;
    *front = temp -> link;
    delete temp;
    return data;

}


int main(){

    return 0;
}