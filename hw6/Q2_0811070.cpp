#include<iostream>

#define MATRIX_ROW 500   //maximum value of nodes
#define MATRIX_COLUMN 2

using namespace std;

int amount = 0;
int start_locate = 0;
int step = 0;
int BinaryTree[MATRIX_ROW];

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
            BinaryTree[i]= -1;
            break;
        }
    }

    return;
}

void Traverse(int now_locate)
{   
    to_left_child(now_locate);
    to_right_child(now_locate);
    to_father(now_locate);

    return;
}

int to_father(int now_locate)
{
    if(now_locate % 2 == 0){
        now_locate = (now_locate - 2) / 2;
    }else{
        now_locate = (now_locate - 1) / 2;
    }
    return Traverse(now_locate);
}

int to_left_child(int now_locate)
{
    now_locate = (now_locate - 1) / 2;
    return Traverse();
}

int to_right_child(int now_locate)
{
    now_locate = (now_locate - 2) / 2;
    return Traverse();
}

int main(){
    input();
    Traverse(start_locate);
    return 0;
}