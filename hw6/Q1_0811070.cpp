#include<iostream>

#define MATRIX 500   //maximum value of nodes

using namespace std;

int amount = 0;
int BinaryTree[MATRIX], Ans[MATRIX];
int ans_cnt = 0;
int start_locate = 0;
int step = 0;

void input();
void to_left_child(int , int );
void to_right_child(int, int );
void to_father(int, int );
void Traverse(int , int, int);
int father_node(int , int );
void arrive(int , int );

int main(){
    input();
    Traverse(start_locate, start_locate, step);
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

void to_left_child(int now_locate, int step_cnt)
{   
    step_cnt --;
    if(step == 0){
        cout << "[]"<<BinaryTree[now_locate];
        return;
    }
    
    int previous_locate = now_locate;
    now_locate = (2* now_locate) + 1;
    arrive(step, now_locate);
    return Traverse(now_locate, previous_locate, step_cnt);
}

void to_right_child(int now_locate, int step_cnt)
{   
    step_cnt --;
    if(step == 0){
        cout << "[]"<<BinaryTree[now_locate];
        return;
    }
    
    int previous_locate = now_locate;
    now_locate = (2* now_locate) + 2;
    return Traverse(now_locate, previous_locate, step_cnt);
}

void to_father(int now_locate, int step_cnt)
{   
    step_cnt --;
    if(step == 0){
        cout << "[]"<<BinaryTree[now_locate];
        return;
    }

    int previous_locate = now_locate;
    if(now_locate == 0 && previous_locate ){
        return to_right_child(now_locate, step_cnt);   //root
    }else if(now_locate == 0 && BinaryTree[2] == -1){  
        return to_left_child(now_locate,step_cnt);   //root
    }else{
        now_locate = (now_locate - 1) / 2;
        return Traverse(now_locate, previous_locate, step_cnt);  //not root
    }
}

int father_node(int now_locate, int previous_locate)
{   
    if(now_locate == 0 && previous_locate == 1){
        return 2;   //root
    }else if(now_locate == 0 && previous_locate == 2){
        return 1;   //root
    }else{
        now_locate = (now_locate - 1) / 2;
        return now_locate;  //not root
    }
}

void arrive(int step, int now_locate)
{
    if(step == 0){
        cout << BinaryTree[now_locate];
    }
}

void Traverse(int now_locate, int previous_locate, int step_cnt)
{   
    cout << now_locate << endl;
    if(BinaryTree[(2* now_locate) + 1] > -1 && (2* now_locate) + 1 != previous_locate && step_cnt > 0){
        //cout << ans_cnt << " " <<now_locate << endl;
        to_left_child(now_locate, step_cnt);
    }

    if(BinaryTree[(2* now_locate) + 2] > -1 && (2* now_locate) + 2 != previous_locate && step_cnt > 0){
        //cout << ans_cnt << " " <<now_locate << endl;
        to_right_child(now_locate, step_cnt);
    }

    if(BinaryTree[father_node(now_locate, previous_locate)] > -1  && father_node(now_locate, previous_locate) != previous_locate && step_cnt > 0){
        //cout << ans_cnt << " " <<now_locate << endl;
        to_father(now_locate, step_cnt);
    }
    ans_cnt++;
}