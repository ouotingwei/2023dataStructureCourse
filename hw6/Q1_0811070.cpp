#include<iostream>
#include<queue>

using namespace std;

typedef struct tagTNode{
    struct tagTNode *left;
    int data;
    struct tagTNode *right;
    struct tagTNode *father;
    //struct tagTNode *father;
}TNode;

TNode *CreateBinaryTreeRoot(int data)
{
    TNode *ptr = new TNode;
    if(data == -1){
        return nullptr;
    }   

    ptr -> data = data;
    ptr -> left = ptr -> right = nullptr;
    ptr -> father = ptr;
    return ptr;
}

TNode *InsertLevelOrder(TNode *node, int data)
{
    if(node == nullpter){
        node = CreateBinaryTreeRoot();
        return node;
    }

    queue<TNode *> q;
    TNode *current = node;

    while(current == True){
        if(current -> left != nullptr){
            q.push(current -> left);
        }else{
            current -> left = CreateBinaryTree();
            return current -> left;
        }

        if(current -> right != nullptr){
            q.push(current -> right);
        }else{
            current -> right = CreateBinaryTree();
            return current -> right;
        }

        current = q.front();
        q.pop();
    }

    return nullptr;
}

TNode *input()
{
    int amount = 0;
    cin >> amount;

    for(int i = 0; i < amount; i++){

    }

}

void LevelOrder(TNode * node)
{
    if(node == nullptr){
        return;
    }

    queue<TNode *> q;
    q.push(node);
    while(q.empty() != true){
        int n = q.size();

        for(int i = 0; i < n; i++){
            TNode *node = q.front();
            q,pop();
            cout << node -> data;
            if(node -> left != nullptr){
                q.push(node -> left);
            }
            if(node -> right != nullptr){
                q.push(node -> right);
            }
        }
    }
}


int main(){


    return 0;
}