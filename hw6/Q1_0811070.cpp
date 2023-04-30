#include<iostream>
#include<vector>

#define MATRIX_ROW 500   //maximum value of nodes
#define MATRIX_COLUMN 2

using namespace std;

int amount = 0;
vector<vector<int>> BinaryTree(MATRIX_ROW, vector<int>(MATRIX_COLUMN));
int start_locate = 0;
int step = 0;

void input()
{
    int start_num = 0;
    cin >> amount;

    for(int i = 0; i < amount; i++){
        int data = 0;
        cin >> data;
        
        if(data < 0 && data >500){
            break;
        }

        BinaryTree[i][0] = data;
        BinaryTree[i][1] = -1;
    }

    cin >> start_num >> step;
    for(int i = 0; i < amount; i++){
        if(BinaryTree[i][0] == start_num){
            start_locate = i;
            BinaryTree[i][1] = 0;
            break;
        }
    }

    return;
}

int Traverse(int now_locate)
{   
    
}

int to_left_child(int now_locate)
{   
    now_locate = (now_locate - 1) / 2;
    return now_locate;
}

int to_right_child(int now_locate)
{
    now_locate = (now_locate - 2) / 2;
    return now_locate;
}

int to_father(int now_locate)
{
    if(now_locate % 2 == 0){
        now_locate = (now_locate - 2) / 2;
    }else if(now_locate % 2 == 1){
        now_locate = (now_locate - 1) / 2;
    }

    return now_locate;
}

int main(){
    input();
    Traverse();
    return 0;
}