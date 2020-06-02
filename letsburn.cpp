#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    bool pathtoval;
    Node *left, *right;
    Node(int data)
    {
        this->data = data;
        pathtoval = false;
        left = right = nullptr;
    }
};

bool path(Node *root, int val, int &len)
{
    if (root == nullptr)
        return false;
    root->pathtoval = true;
    len++;
    if (root->data == val)
        return true;
    if (path(root->left, val, len) || path(root->right, val, len))
        return true;
    root->pathtoval = false;
    len--;
    return false;
}

void preorder(Node *root, int len, int &maxim)
{
    if (root == nullptr)
        return;
    if (root->pathtoval)
        len--;
    else
        len++;
    maxim = max(maxim, len);
    preorder(root->left, len, maxim);
    preorder(root->right, len, maxim);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->left->left->left = new Node(8);
    root->left->right->left = new Node(9);
    root->left->right->right = new Node(10);
    root->left->right->left->left = new Node(11);
    root->left->right->left->left->left = new Node(12);
    int target = 1;
    int len = 0;
    if (path(root, target, len))
    {
        preorder(root, len, len);
        cout << "Time taken to burn tree: " << len << "s" << endl;
    }
    else
    {
        cout << "No such target node found asshole..." << endl;
    }

    return 0;
}