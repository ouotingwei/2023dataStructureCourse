#include<iostream>
#include<vector>

#define MATRIX_ROW 500   //maximum value of nodes
#define MATRIX_COLUMN 2

using namespace std;

vector<vector<int>> BinaryTree(MATRIX_ROW, vector<int>(MATRIX_COLUMN));
int amount = 0;

void input()
{
    cin >> amount;

    for(int i = 0; i < amount; i++){
        int data = 0;
        cin >> data;
        BinaryTree[i][0] = data;
        BinaryTree[i][1] = false;
    }
    
    return;
}

void Traverse()
{
    for(int i = 0; i < 10; i++){
        cout<< BinaryTree[i][0] << " " << BinaryTree[i][1] << endl;
    }
}

int main(){
    input();
    Traverse();
    return 0;
}