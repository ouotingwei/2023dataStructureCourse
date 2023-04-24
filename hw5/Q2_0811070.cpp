#include <iostream>
#include <queue>
#include <math.h>

using namespace std;

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
}

bool CanGoHome(treeNode *root)
{
    // TODO
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
}111111111111111111111111