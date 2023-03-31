#include<iostream>

using namespace std;

typedef struct stackList{
    int data;
    struct stackList *next;
}stackList;

int push(stackList *s, int x){
    stackList *p;
    if( (p = new stackList) == NULL){
        return false;
    }

    p -> data = x;
    p -> next = s -> next;
    s -> next = p;

    return true;
}

int pop(stackList *s){
    stackList *p = s -> next;
    if(p == NULL){
        return false;
    }

    int x = p -> data;
    s -> next = p -> next;
    delete p;
    return x;
}

int main(){
    stackList stk;
    push(&stk, 30);
    push(&stk, 15);
    push(&stk, 5);
    
    while(1){
        cout << pop(&stk) << endl;
    }

    return 0;
}