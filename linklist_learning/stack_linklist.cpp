#include<iostream>

using namespace std;

typedef struct tagStackList{
    int data;
    struct tagStackList *next;

}StackList;

int Push(StackList *S , int X);
int Pop(StackList *S , int *X);

int main(){
    int data1;

    StackList TopOfStk; // first node
    Push(&TopOfStk, 30);
    Push(&TopOfStk, 15);
    Push(&TopOfStk, 9);
    Pop(&TopOfStk, &data1); 
    cout<<data1<<endl;

    return 0;
}

int Push(StackList *S , int X){
    StackList *p;
    if( (p = new StackList) == NULL ){
        return false; //memory allocation failed
    }

    p -> data = X;
    p -> next = S -> next;
    S -> next = p;
    return true;

}

int Pop(StackList *S , int *X){
    StackList *p = S -> next;
    if(p == NULL){
        return false;
    }

    *X = p -> data;
    S ->next = p -> next;
    delete p;
    return true;
}