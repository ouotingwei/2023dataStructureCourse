#include<iostream>
//#include<vector>

#define MATRIX_ROW 500   //maximum value of nodes
//#define MATRIX_COLUMN 2

using namespace std;

int amount = 0;
//vector<vector<int>> BinaryTree(MATRIX_ROW, vector<int>(MATRIX_COLUMN));
int BinaryTree[MATRIX_ROW] = {-1};
int start_locate = 0;
int step = 0;
int step_cnt = -1;
int direct_cnt = 0;

void input()
{
    int start_num = 0;
    cin >> amount;

    for(int i = 0; i < amount; i++){
        int data = 0;
        cin >> data;
        BinaryTree[i] = data;
    }

    cin >> start_num >> step;
    for(int i = 0; i < amount; i++){
        if(BinaryTree[i] == start_num){
            start_locate = i;
            break;
        }
    }

    return;
}

int Traverse(int now_locate, int previous_locate)
{   
    step_cnt ++;

    if( BinaryTree[to_left_child(now_locate)] != -1 && previous_locate != to_left_child(now_locate) ){
        Traverse(to_left_child(now_locate), now_locate);
    }

    if( BinaryTree[to_right_child(now_locate)] != -1 && previous_locate != to_right_child(now_locate)  ){
        Traverse(to_right_child(now_locate), now_locate);
    }

    if( BinaryTree[to_father(now_locate)] != -1 && previous_locate != to_father(now_locate) ){
        Traverse(to_father(now_locate), now_locate);
    }

    BinaryTree[now_locate] = -1;
    return Traverse(previous_locate, now_locate);
}

int to_left_child(int now_locate)
{   
    if(step_cnt == step){
        cout << BinaryTree[now_locate];
    }
    now_locate = (now_locate - 1) / 2;
    return now_locate;
}

int to_right_child(int now_locate)
{   
    if(step_cnt == step){
        cout << BinaryTree[now_locate];
    }
    now_locate = (now_locate - 2) / 2;
    return now_locate;
}

int to_father(int now_locate)
{
    if(step_cnt == step){
        cout << BinaryTree[now_locate];
    }
    if(now_locate % 2 == 0){
        now_locate = (now_locate - 2) / 2;
    }else if(now_locate % 2 == 1){
        now_locate = (now_locate - 1) / 2;
    }

    return now_locate;
}

int main(){
    input();
    Traverse(start_locate, start_locate);
    return 0;
}