//Left view of a Binary Tree.......
//      1
//     /  \
//    2     3
//   / \    / \
//  4   5  6   7   ---> The output is- 1 2 4

#include <iostream>
#include <list>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int data)
{
    struct Node *node = (struct Node *)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void leftView(struct Node *root, int level, int *maxLevel, list<int> *leftViewElements)
{
    if (root == NULL)
    {
        return;
    }
    if (*maxLevel < level)
    {
        leftViewElements->push_back(root->data);
        *maxLevel = level;
    }
    leftView(root->left, level + 1, maxLevel, leftViewElements);
    leftView(root->right, level + 1, maxLevel, leftViewElements);
}

int main()
{
    int maxlevel = 0;
    //Binary Tree Example-1....
    struct Node *root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    list<int> *leftViewElements = new list<int>();
    leftView(root, 1, &maxlevel, leftViewElements); //Output- 1 2 4.....
    maxlevel = 0;

    //Binary Tree Example-2.....
    struct Node *root1 = newNode(1);
    root1->left = newNode(2);
    root1->right = newNode(3);
    root1->right->left = newNode(5);
    list<int> *leftViewElements1 = new list<int>();
    leftView(root1, 1, &maxlevel, leftViewElements1);

    for (int a : *leftViewElements)
    {
        cout << a << " ";
    }
    cout << endl;
    for (int b : *leftViewElements1)
    {
        cout << b << " ";
    }
    return 0;
}