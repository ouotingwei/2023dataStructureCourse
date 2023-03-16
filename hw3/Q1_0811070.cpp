/*Data Structure HW3-1 by TingweiOu 0811070*/
#include<iostream>

using namespace std;

int MAX_ITEM = 0;  //MAX_ITEM = Number Of Days

typedef struct{
	int Item[MAX_ITEM];
	int Top = -1;
}stack;

int isFull(stack *s);
int ismpty(stack *s);
int pop(stack *s, int *x);
int push(stack *s, int *x);
int inputCheckN();

int main(){
	MAX_ITEM = inputCheckN();
	stack stk;
	
	return 0;
}

int isFull(stack *s){
	if(s -> Top == MAX_ITEM-1 ){
		return false;
	}else{
		return true;
	}
}

int isEmpty(stack *s){
	if(s -> Top == -1){
		return false;
	}else{
		return true;
	}
}

int pop(stack *s, int *x){
	if(isEmpty(s) == true){
		return false;
	}
	
	*x = s -> Item[s -> Top];
	s -> Top--;
	return true;
}

int push(stack *s, int *x){
	if(isFull(s) == true){
		return false;
	}
	
	s -> Top = s -> Top + 1;
	s -> Item[s -> Top] = x;
	
	return true;
}

int inputCheckN(){
	int input = 0;
	cin >> input;
	if(input > 0 && input <= 100){
		return input;
	}else{
		return false;
	}
}
