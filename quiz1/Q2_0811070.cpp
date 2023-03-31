#include<iostream>
#define MAX_ITEM 100

using namespace std;

typedef struct{
	int Item[MAX_ITEM];
	int Top = -1;
}stack;

int isEmpty(stack *);
int isFull(stack *);
int pop(stack *);
int push(stack *, int);
int inputcheckN();
int inputcheckPoint();

int main(){
	stack stk;
	int N = inputcheckN();
	int point[N] = {0};
	int span[N] = {0};
	
	for(int i = 0; i < N; i++){
		point[i] = inputcheckPoint();
	}
	
	for(int i = 0; i < N; i++){
		while(1){
			if(isEmpty(&stk) == false){
				if(point[ stk.Item[ stk.Top ] ] <= point[i]){
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
	
	cout << endl;
	for(int i = 0; i < N; i++){
		cout << span[i] << " ";
	}
	cout << endl;
	
	return 0;
}

int isEmpty(stack *s){
	if( s -> Top == -1 ){
		return true;
	}else{
		return false;
	}
}

int isFull(stack *s){
	if( s -> Top == MAX_ITEM - 1 ){
		return true;
	}else{
		return false;
	}
}

int pop(stack *s){
	if( isEmpty(s) ){
		return false;
	}
	
	int x = s -> Item[ s -> Top];
	s -> Top --;
	
	return x;
}

int push(stack *s, int x){
	if( isFull(s) ){
		return false;
	}
	
	s -> Top++;
	s -> Item[ s -> Top ] = x;
	
	return true;
}

int inputcheckN(){
	int n = 0;
	cin >> n;
	if(n > 0 && n <= 100){
		return n;
	}else{
		cout << " error " << endl; 
		return inputcheckN();
	}
}

int inputcheckPoint(){
	int point = 0;
	cin >> point;
	if(point > 0 && point <= 1000){
		return point;
	}else{
		cout << " error " << endl; 
		return inputcheckPoint();
	}
}
