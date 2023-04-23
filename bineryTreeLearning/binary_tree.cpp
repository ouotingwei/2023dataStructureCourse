#include<iostream>

using namespace std;

typedef struct tagTNode
{
    struct tagTNode *left_c;    //point to left subnode
    char data;                  //data
    struct tagTNode *right_c;   //point to right subnode
}TNode;

TNode *CreateBinaryTree();
void PreOrder(TNode *);
void InOrder(TNode *);
void PostOrder(TNode *);

int main(){
    TNode *myTree;
    myTree = CreateBinaryTree();

    cout << "PreOrder : ";
    PreOrder(myTree);
    cout << endl;
    cout << "InOrder : ";
    InOrder(myTree);
    cout << endl;
    cout << "PostOrder : ";
    PostOrder(myTree);
    cout << endl;

    return 0;
}

TNode *CreateBinaryTree()
{
    TNode *ptr;
    char data;
    cin >> data;
    if( data == '0'){
        return NULL;    //當輸入資料為0時停止建立子節點
    }

    ptr = new TNode;
    ptr -> data = data;
    ptr -> left_c = CreateBinaryTree();
    ptr -> right_c = CreateBinaryTree();
    return ptr;
}

void PreOrder(TNode *p)
{
    if(p != NULL){
        cout << p -> data;
        PreOrder(p -> left_c);
        PreOrder(p -> right_c);
    }
}

void InOrder(TNode *p)
{
    if( p != NULL){
        InOrder(p -> left_c);
        cout << p -> data;
        InOrder(p -> right_c);
    }
}

void PostOrder(TNode *p)
{
    if( p != NULL){
        PostOrder( p -> left_c);
        PostOrder( p -> right_c);
        cout << p -> data;
    }
}
