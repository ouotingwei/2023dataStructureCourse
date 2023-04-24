#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

int Round = 0;

typedef struct treeNode
{
    int data;
    struct treeNode *left;
    struct treeNode *right;
} treeNode;

// node
treeNode *CreateNode(int data)
{
    treeNode *temp = new treeNode;
    temp->data = data;
    temp->left = temp->right = nullptr;
    return temp;
}

treeNode *InsertLevelOrder(treeNode *node, int data)
{
    if (node == nullptr)
    {
        node = CreateNode(data);
        return node;
    }

    std::queue<treeNode *> q;
    treeNode *current = node;

    while (current)
    {
        if (current->left != nullptr)
        {
            q.push(current->left);
        }
        else
        {
            current->left = CreateNode(data);
            return current->left;
        }
        if (current->right != nullptr)
        {
            q.push(current->right);
        }
        else
        {
            current->right = CreateNode(data);
            return current->right;
        }
        current = q.front();
        q.pop();
    }
    return nullptr;
}

// hint: you can use InsertLevelOrder()
// reference of level-order insertion:
// http://alrightchiu.github.io/SecondRound/binary-tree-jian-li-yi-ke-binary-tree.html#func2
// you can modify this function
treeNode *input()
{
    treeNode *root = CreateNode(0);
    treeNode *red = InsertLevelOrder(root, 1);
    treeNode *black = InsertLevelOrder(root, 1);
    // TODO
    cin >> Round;   //total amount = 2^k - 1
    int inputdata;

    for(int i = 1; i <= Round; i++){
        if(i % 2 == 1){ //red first!
            for(int j = 0; j < pow(2, i); j++){
                cin >> inputdata;
                treeNode *root = InsertLevelOrder(red, inputdata);
            }

            for(int j = 0; j < pow(2, i); j++){
                cin >> inputdata;
                treeNode *root = InsertLevelOrder(black, inputdata);
            }
        }else{
            for(int j = 0; j < pow(2, i); j++){
                cin >> inputdata;
                treeNode *root = InsertLevelOrder(black, inputdata);
            }

            for(int j = 0; j < pow(2, i); j++){
                cin >> inputdata;
                treeNode *root = InsertLevelOrder(red, inputdata);
            }
        }
    }

    return root;
}

bool CanGoHome(treeNode *root)
{
    // TODO
    int level[100] = {0};
    int roundCNT = 0;
    int compareCNT = 0;

    if (root == NULL) {
        return false;
    }
    queue<treeNode*> q;
    q.push(root);
    while (q.empty() != true) {
        int n = q.size();

        for (int i = 0; i < n; i++) {
            treeNode* node = q.front();
            q.pop();
            level[i] = node -> data;
            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
        }

        for(int i = 0; i < n/2; i++){
            if(level[i] != level[n - i - 1]){
                return true;
            }
        }

        for(int i = 0; i < n; i++){
            level[i] = 0;
        }

        roundCNT++;
    }

    return false;

}

// DO NOT modify main function
int main()
{
    treeNode *root = input();
    if (CanGoHome(root))
        cout << "true" << endl;
    else
        cout << "false" << endl;
    return 0;
}