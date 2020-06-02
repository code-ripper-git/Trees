#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;

    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

void countBST(Node *root, Node *&prev, bool &isbst, int &i)
{

    if (root == nullptr)
    {
        isbst = true;
        prev = nullptr;
        return;
    }
    if (root->left == nullptr && root->right == nullptr)
    {
        isbst = true;
        prev = root;
        i++;
        return;
    }
    bool isleft = false, isright = false;
    countBST(root->left, prev, isleft, i);
    if (prev == nullptr || prev->data < root->data)
        isbst = isleft;
    countBST(root->right, prev, isright, i);
    isbst = isbst && isright && (prev == nullptr || prev->data > root->data);
    prev = root;
    if (isbst)
        i++;
}

int main()
{
    /*
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);
    */
    /*
    Node *root = new Node(5);
    root->left = new Node(9);
    root->right = new Node(3);
    root->left->left = new Node(6);
    root->right->right = new Node(4);
    root->left->left->left = new Node(8);
    root->left->left->right = new Node(7);
    root->left->left->right->left = new Node(3);
    root->left->left->right->right = new Node(9);
    */

    Node *root = new Node(11);
    root->left = new Node(8);
    root->right = new Node(10);
    root->left->left = new Node(5);
    root->right->right = new Node(8);
    root->left->left->left = new Node(4);
    root->left->left->right = new Node(6);
    root->right->left = new Node(9);
    int i = 0;
    Node *prev = nullptr;
    bool bst = false;
    countBST(root, prev, bst, i);
    cout << i << endl;

    return 0;
}
