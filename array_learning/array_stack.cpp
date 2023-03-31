#include<iostream>
#include"dataStructure.h"

using namespace std;

#define MAX_ITEM 5

typedef struct tagStack{
    int Item[MAX_ITEM];
    int Top = -1;
}Stack;

int IsFull(Stack *s);
int IsEmpty(Stack *s);
int pop(Stack *s, int *x);
int push(Stack *s, int x);

int main(){
    Stack stk;

    push(&stk, 11);
    push(&stk, 12);
    push(&stk, 13);
    push(&stk, 14);
    push(&stk, 15);

    for(int i = 0; i < MAX_ITEM; i++){
        cout<<i<<" : "<<stk.Item[i]<<endl;
    }

    int First, Second;

    pop( & stk, &First);
    pop( & stk, &Second);

    cout<<"First = "<<First<<endl;
    cout<<"Second = "<<Second<<endl;

    return 0;
}

int push(Stack *s, int x){
    if(IsFull(s) == true){
        return false;
    }

    s -> Top++;
    s -> Item[s -> Top] = x;
    return true;
}

int IsFull(Stack *s){
    if(s -> Top == (MAX_ITEM) - 1){
        return true;

    }else{
        return false;

    }
}

int pop(Stack *s, int *x){
    if(IsEmpty(s)){
        return false;

    }

    *x = s -> Item[s -> Top];
    s -> Top--;
    return true;
}

int IsEmpty(Stack *s){
    if(s -> Top == -1){
        return true;

    }else{
        return false;
        
    }
}
