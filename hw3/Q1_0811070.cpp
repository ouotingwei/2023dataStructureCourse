/*Data Structure HW3-1 by TingweiOu 0811070*/
#include<iostream>
#define MAX_ITEM 100

using namespace std;

typedef struct{
	int Item[MAX_ITEM];
	int Top = -1;
}stack;

int isFull(stack *);
int isEmpty(stack *);
int pop(stack *);
int push(stack *, int );
int inputCheckN();
int inputCheckPoints();

int main(){
	stack stk;
	int Points = 0;
	int N = inputCheckN();
	int outPut[N] = {0};

	push(&stk, inputCheckPoints());
	outPut[0] = 1;
	int i = 1;
	while(i < N){
		if(isEmpty(&stk) && stk.Item[stk.Top] <= Points){
			pop(&stk);
		}else{
			Points = inputCheckPoints();
			push(&stk, Points);
			outPut[i] = i - stk.Top + 1;
			i++;
		}
	}

	cout << endl;
	for(int i = 0; i < N; i++){
		cout << outPut[i] << " ";
	}
	cout << endl;
	
	return 0;
}

int isFull(stack *s){
	if(s -> Top == MAX_ITEM - 1){
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

int inputCheckPoints(){
	int input = 0;
	cin >> input;
	if(input > 0 && input <= 1000){
		return input;
	}else{
		return false;
	}
}
