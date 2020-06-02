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

void countBST(Node *root, Node *&prev, bool &isbst, int &i, int &sz, int &maxi)
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
        sz++;
        return;
    }
    bool isleft = false, isright = false;
    countBST(root->left, prev, isleft, i, sz, maxi);
    if (prev == nullptr || prev->data < root->data)
        isbst = isleft;
    countBST(root->right, prev, isright, i, sz, maxi);
    isbst = isbst && isright && (prev == nullptr || prev->data > root->data);
    prev = root;
    if (isbst)
    {
        i++;
        sz++;
    }
    else
        sz = 0;
    maxi = max(maxi, sz);
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
    int i = 0, size = 0, max = 0;
    Node *prev = nullptr;
    bool bst = false;
    countBST(root, prev, bst, i, size, max);
    cout << i << endl;
    cout << max << endl;

    return 0;
}
