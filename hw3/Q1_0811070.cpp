/*Data Structure HW3-1 by TingweiOu 0811070*/
#include<iostream>

using namespace std;
#define MAX_ITEM 5

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

	int outPutCNT = 0;

	for(int i = 0; i < N; i++){
		outPut[i] = inputCheckPoints();
	}

	for(int i = 0; i < N; i++){
		cout << outPut[i] << " ";
	}
	cout << endl;
	
	for(int i = 0; i < N; i++){
		cout << stk.Top << endl;
		if(stk.Top != -1 && stk.Item[stk.Top] <= outPut[outPutCNT]){
			pop(&stk);
		}else if(stk.Top != -1 && stk.Item[stk.Top] > outPut[outPutCNT]){
			outPut[outPutCNT] = outPutCNT - stk.Top;
			cout << "case 2 : " << outPut[outPutCNT] << endl;
			push(&stk, outPut[outPutCNT]);
			outPutCNT++;
		}else{
			outPut[outPutCNT] = outPutCNT - stk.Top;
			cout << "case 3 : " << outPut[outPutCNT] << endl;
			push(&stk, outPut[outPutCNT]);
			outPutCNT++;
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
