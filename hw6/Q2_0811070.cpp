#include<iostream>
#include<algorithm>

#define MATRIX 500   //maximum value of nodes

using namespace std;

int amount = 0;
int BinaryTree[MATRIX];
int locate[MATRIX];
int cnt[MATRIX];
int ans_cnt = 0;
int start_locate = 0;

void input();
void to_left_child(int , int);
void to_right_child(int, int);
void to_father(int, int , int);
void Traverse(int, int, int);
int father_node(int, int);
void output();

int main(){
    input();
    Traverse(start_locate, start_locate, 0);
    //output();
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

    cin >> start_num ;
    for(int i = 0; i < amount; i++){
        if(BinaryTree[i] == start_num){
            start_locate = i;
            break;
        }
    }
}

void to_left_child(int now_locate, int step_cnt)
{   
    step_cnt ++;
    int previous_locate = now_locate;
    now_locate = (2* now_locate) + 1;
    return Traverse(now_locate, previous_locate, step_cnt);
}

void to_right_child(int now_locate, int step_cnt)
{   
    step_cnt ++;
    int previous_locate = now_locate;
    now_locate = (2* now_locate) + 2;
    return Traverse(now_locate, previous_locate, step_cnt);
}

void to_father(int now_locate, int previous_locate, int step_cnt)
{   
    step_cnt ++;
    if(now_locate == 0 && previous_locate == 1){
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

void Traverse(int now_locate, int previous_locate, int step_cnt)
{   
    if(BinaryTree[(2* now_locate) + 1] > -1 && (2* now_locate) + 1 != previous_locate ){
        to_left_child(now_locate, step_cnt);
    }

    if(BinaryTree[(2* now_locate) + 2] > -1 && (2* now_locate) + 2 != previous_locate ){
        to_right_child(now_locate, step_cnt);
    }

    if(BinaryTree[father_node(now_locate, previous_locate)] > -1  && father_node(now_locate, previous_locate) != previous_locate ){
        to_father(now_locate, previous_locate, step_cnt);
    }
    
    cnt[ans_cnt] = step_cnt;
    locate[ans_cnt] = now_locate;
    //cout << now_locate << " " << step_cnt << endl;
    ans_cnt ++;
}

void output(){
    int output[MATRIX] = {0};
    int count = 0;
    int temp = cnt[0];

    for(int i = 1; i < ans_cnt; i++){
        if(cnt[i] > temp){
            temp = cnt[i];
        }
    }
    
    for(int i = 0; i < ans_cnt; i++){
        if(cnt[i] == temp){
            output[count] = BinaryTree[locate[i]];
            count ++;
        }
    }

    sort(output, output + count);

    for(int i = count - 1; i >= 0; i--){
        cout << output[i] << " ";
    }

    cout << endl;

}