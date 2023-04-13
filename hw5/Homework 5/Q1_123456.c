#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>
#define max 9999

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

//queue
treeNode* q[max]={NULL};
int front=0;
int rear=0;
int itemcount=0;

treeNode* pop(){
	front++;
	return q[front-1];	
}

bool isEmpty(){
	return itemcount == 0;
}

bool isFull(){
	return itemcount == max;
}

void push(treeNode* data){
	if(!isFull()){
		q[rear] = data;
		rear++;
		itemcount++;
	}
}

void clear(){
	memset(q, NULL, max);
	front=0;
    rear=0;
    itemcount=0;
}

//node
treeNode* CreateNode(int data){
    treeNode* temp;
    temp = (treeNode *)malloc(sizeof(treeNode));
    temp -> data = data;
    temp -> left = temp -> right = NULL; 
    return temp;
}

treeNode* InsertLevelOrder(treeNode *node, int data){
	if (node == NULL) {
    	node = CreateNode(data);
    	return node;
    }
    clear();
    push(node);
 
    while (!isEmpty()) {
        treeNode* temp = pop();
 
        if (temp->left != NULL)
            push(temp->left);
        else {
            temp->left = CreateNode(data);
            return temp->left;
        }
 
        if (temp->right != NULL)
            push(temp->right);
        else {
            temp->right = CreateNode(data);
            return temp->right;
        }
    }   
}


//hint: you can use InsertLevelOrder()
//reference of level-order insertion:
//http://alrightchiu.github.io/SecondRound/binary-tree-jian-li-yi-ke-binary-tree.html#func2
//you can modify this function
treeNode* input(){
	treeNode *root = NULL;
	root = InsertLevelOrder(root, 0);
	treeNode* red = InsertLevelOrder(root, 1);
	treeNode* black = InsertLevelOrder(root, 1);
	//TODO

}

void LevelOrder(treeNode *node){
	//TODO

}

//DO NOT modify main function
int main(){	
	treeNode *root = input();
	LevelOrder(root);
	return 0;
}
