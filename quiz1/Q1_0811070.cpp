#include<iostream>

using namespace std;

int inputcheckn();
int inputcheckleaves();

int main(){
	int n = inputcheckn();
	int leaves[n + 1] = {0};
	leaves[n] = 1;
	int output[n + 1] = {0};
	
	for(int i = 0; i < n; i++){
		leaves[i] = inputcheckleaves();
	}
	
	int cnt = 0;
	int tempnum = 0;
	for(int i = 0; i < n; i++){
		if(leaves[i] == 0){
			tempnum++;
		}else{
			output[cnt] = tempnum;
			cnt++;
			tempnum = 0;	
		}
	}
	
	int max = 0;
	for(int i = 0; i < n; i++){
		if(output[i] > max){
			max = output[i];
		}
	}
	
	cout << max << endl;
	
	return 0;
}

int inputcheckn(){
	int n = 0;
	cin >> n;
	if(n >= 1 && n <= 1000){
		return n;
	}else{
		cout << "error" << endl; 
		return inputcheckn();
	}
}

int inputcheckleaves(){
	int data = 0;
	cin >> data;
	if(data >= -1 && data <= 1){
		return data;
	}else{
		cout << "error" << endl; 
		return inputcheckleaves();
	} 
}
