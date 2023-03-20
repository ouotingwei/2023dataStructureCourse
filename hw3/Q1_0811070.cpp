/*Data Structure HW3 by TingweiOu 0811070*/
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
int push(stack *, int);
int inputCheckN();
int inputCheckPoints();

int main(){
	stack stk;
	int N = inputCheckN();
	int Points[N] = {0};
	int span[N] = {0};

	//scan input data
	
	for(int i = 0; i < N; i++){
		Points[i] = inputCheckPoints();
	}	
	
	for(int i = 0; i < N; i++ ){
		while(1){
			if(isEmpty(&stk) == false){
				if(Points[  stk.Item[stk.Top] ] <= Points[i]){
					pop(&stk);
				}else{
					span[i] = i - stk.Item[stk.Top];
					push(&stk, i);
					
					break;
				}
				
			}else{
				span[i] = i + 1;
				push(&stk, i);
				
				break;
			}
		}
	}
	
	for(int i = 0; i < N; i++){
		cout << span[i] << " ";
	}
	cout << endl;
	
	return 0;
}

int isFull(stack *s){
	if(s -> Top == MAX_ITEM - 1){
		return true;
	}else{
		return false;
	}
}

int isEmpty(stack *s){
	if(s -> Top == -1){
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
