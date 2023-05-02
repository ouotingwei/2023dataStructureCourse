#include<iostream>
#include<algorithm>

#define MATRIX 500   //maximum value of nodes

using namespace std;

int amount = 0;
int BinaryTree[MATRIX] = {0};
int Ans[MATRIX] = {0};
int ans_cnt = 0;
int start_locate = 0;
int step = 0;

void input();
void to_left_child(int , int, int);
void to_right_child(int, int, int);
void to_father(int, int , int);
void Traverse(int , int, int, int);
void output();

int main(){
    input();
    to_left_child(start_locate, start_locate, step);
    to_right_child(start_locate, start_locate, step);
    to_father(start_locate, start_locate, step);
    output();
    return 0;
}

void input()
{
    for(int i = 0; i < 500; i++){
        BinaryTree[i] = -1;
    }

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

void to_left_child(int now_locate, int previous_locate, int step_cnt)
{   
    int pre_dir = 1;
    previous_locate = now_locate;
    step_cnt --;
    now_locate = (2* now_locate) + 1;
    if(now_locate == previous_locate){
        return;
    }
    return Traverse(now_locate, previous_locate, step_cnt, pre_dir);
}

void to_right_child(int now_locate, int previous_locate, int step_cnt)
{   
    int pre_dir = 2;
    previous_locate = now_locate;
    step_cnt --;
    now_locate = (2* now_locate) + 2;
    if(now_locate == previous_locate){
        return;
    }
    return Traverse(now_locate, previous_locate, step_cnt, pre_dir);
}

void to_father(int now_locate, int previous_locate, int step_cnt)
{   
    int pre_dir = 3;
    previous_locate = now_locate;
    step_cnt --;
    if(now_locate == 0 && previous_locate == 1){
        return to_right_child(now_locate, previous_locate, step_cnt);   //root
    }
    if(now_locate == 0 && previous_locate == 2){
        return to_left_child(now_locate, previous_locate, step_cnt);   //root
    }
    now_locate = (now_locate - 1) / 2;
    if(now_locate == previous_locate){
        return;
    }
    return Traverse(now_locate, previous_locate, step_cnt, pre_dir);  //not root
    
}

void Traverse(int now_locate, int previous_locate, int step_cnt, int pre_dir)
{   
    if(BinaryTree[(2* now_locate) + 1] != -1 && BinaryTree[(2* now_locate) + 2] != -1 && pre_dir == 1 && step_cnt > 0 ){
        to_right_child(now_locate, previous_locate, step_cnt);
        to_left_child(now_locate, previous_locate, step_cnt);
    }

    if(BinaryTree[(2* now_locate) + 1] != -1 && BinaryTree[(2* now_locate) + 2] != -1 &&pre_dir == 2 && step_cnt > 0 ){
        to_right_child(now_locate, previous_locate, step_cnt);
        to_left_child(now_locate, previous_locate, step_cnt);
    }

    if(previous_locate == (2*now_locate) + 1 && pre_dir == 3 && step_cnt > 0 ){
        to_father(now_locate, previous_locate, step_cnt);
        to_right_child(now_locate, previous_locate, step_cnt);
    }

    if(previous_locate == (2*now_locate) + 2 && pre_dir == 3 && step_cnt > 0 ){
        to_father(now_locate, previous_locate, step_cnt);
        to_left_child(now_locate, previous_locate, step_cnt);
    }

    if(step_cnt == 0 ){
        Ans[ans_cnt] = BinaryTree[now_locate];
        ans_cnt ++;
    }
}

void output(){
    sort(Ans, Ans + ans_cnt);
    for(int i = ans_cnt - 1; i >= 0; i--){
        cout << Ans[i] << " ";
    }
    cout << endl;
}