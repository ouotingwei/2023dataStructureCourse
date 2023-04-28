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
        
        if(data < 0 && data >500){
            break;
        }

        BinaryTree[i][0] = data;
        BinaryTree[i][1] = false;
    }
    
    return;
}

void Traverse()
{   
    int step = 0;
    int node_locate = 0;
    int node_value = 0;
    cin >> node_value >> step;

    for(int i = 0; i < amount; i++){
        if(BinaryTree[i][0] == node_value){
            node_locate = i;
            BinaryTree[i][1] = 0;
            break;
        }
    }

    while(1){
        
    }
    
    return;
}

int to_father(int node_locate)
{   
    if(node_locate % 2 == 0){    //even
        node_locate = (node_locate - 2) / 2;
    }else{  //odd
        node_locate = (node_locate - 1) / 2;
    }

    BinaryTree[node_locate][1] = 0;

    return node_locate;
}

int to_left_child(int node_locate)
{
    node_locate = (node_locate * 2) + 1;
    return node_locate;
}

int to_right_child(int node_locate)
{
    node_locate = (node_locate * 2) + 2;
    return node_locate;
}

int main(){
    input();
    Traverse();
    return 0;
}