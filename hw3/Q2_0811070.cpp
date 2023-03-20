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

int main(){
	stack stk;
	stack stkB;
	int day = 0;
	cin >> day;
	int points[day] = {0};
	int spanForward[day] = {0};
	int spanBackward[day] = {0};
	
	for(int i = 0; i < day; i++){
		cin >> points[i];
	}
	
	//forward
	for(int i = 0; i < day; i++ ){
		while(1){
			if(isEmpty(&stk) == false){
				if(points[ stk.Item[stk.Top] ] <= points[i]){
					pop(&stk);
				}else{
					spanForward[i] = i - stk.Item[stk.Top];
					push(&stk, i);
					
					break;
				}
				
			}else{
				spanForward[i] = i + 1;
				push(&stk, i);
				
				break;
			}
		}
	}
	
	//backward
	for(int i = day; i >= 0; i-- ){
		
		while(1){
			if(isEmpty(&stkB) == false){
				if(points[ stkB.Item[stkB.Top] ] <= points[i]){
					pop(&stkB);
				}else{
					spanBackward[i] = spanBackward[i] + (stkB.Item[stkB.Top] - i);
					push(&stkB, i);
					
					break;
				}
				
			}else{
				spanBackward[i] = spanBackward[i] + (day - i) ;
				push(&stkB, i);
				
				break;
			}
		}
	}
	
	for(int i = 0; i < day; i++){
		cout << spanForward[i] + spanBackward[i] - 1 << " ";
	}
	cout << endl;
	
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
	if(s -> Top == MAX_ITEM - 1){
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
	s -> Item[ s -> Top ] = x;
	
	return true;
}
