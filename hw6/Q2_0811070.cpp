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
    if(to_left_child(now_locate) != -1){
        return Traverse(to_left_child(now_locate));
    }

    if(to_right_child(now_locate) != -1){

    }

    if(to_father(now_locate) != -1){

    }
    
    return;
}

int to_father(int now_locate)
{
    int father_locate = 0;
    if(now_locate % 2 == 0){
        father_locate = (now_locate - 2) / 2;
    }else if(){ 
        father_locate = (now_locate - 1) / 2;
    }
    return father_locate;
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

int main(){
    input();
    Traverse(start_locate);
    return 0;
}