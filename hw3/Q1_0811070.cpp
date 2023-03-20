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
int push(stack *, int);
int inputCheckN();
int inputCheckPoints();

int main(){
	stack stk;
	int N = inputCheckN();
	int outPut[N] = {0};
	bool flag = true;

	//scan input data
	
	for(int i = 0; i < N; i++){
		outPut[i] = inputCheckPoints();
	}	

	int CNT = 0;
	while(flag == true){
		
		cout << endl;
		cout << "cnt : " << CNT << endl;
		cout << "outPut[CNT] : " << outPut[CNT] << endl;
		cout << "stk.Top : " << stk.Top << endl;
		cout << "outPut[CNT - 1]" << outPut[CNT - 1] << endl;
		
		if(isEmpty(&stk) == false && stk.Item[stk.Top] <= outPut[CNT]){
			cout << "[case 1]" << endl;
			//cout << stk.Item[stk.Top] << endl;
			pop(&stk); // !
		}else if(isEmpty(&stk) == true ){
			cout << "[case 2]" << endl;
			push(&stk, outPut[CNT]);
			cout << "stk.Item[stk.Top] : " << stk.Item[stk.Top] << endl;
			outPut[CNT] = CNT - stk.Top + 1; 
			CNT++;
		}else{
			cout << "[case 3]" << endl;
			push(&stk, outPut[CNT]);
			cout << "stk.Item[stk.Top] : " << stk.Item[stk.Top] << endl;
			outPut[CNT] = CNT - stk.Top + 1; 
			CNT ++;
		}
		
		if(CNT == N){
			flag = false;
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
