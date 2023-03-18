#include<iostream>
# define MAX_ITEM 100

using namespace std;

typedef struct{
    int Item[MAX_ITEM];
    int Top = -1;
}stack;

int isEmpty(stack *);
int isFull(stack *);
int pop(stack *);
int push(stack *, int);

int main(){
    stack stk;
    push(&stk, 1);
    push(&stk, 2);
    push(&stk, 3);

    for (int i = 0; i < 3; i++){ 
        cout  << "push to stack : " << stk.Item[i] << endl;  
    }

    for (int i = 0; i < 3; i++){ 
        cout  << "pop from stack : " << pop(&stk) << endl;  
    }



    return 0;
}

int isEmpty(stack *s){
    if(s -> Top == -1){
        return true;
    }else{
        return false;
    }
}

int isFull(stack *s){
    if( s -> Top == MAX_ITEM - 1){
        return true;
    }else{
        return false;
    }
}

int pop(stack *s){
    if(isEmpty(s) == true){
        return false;
    }

    int x = s -> Item[s -> Top];
    s -> Top--;

    return x;
}

int push(stack *s, int x){
    if(isFull(s) == true){
        return false;
    }
    
    s -> Top++;
    s -> Item[s -> Top] = x;

    return true;
}