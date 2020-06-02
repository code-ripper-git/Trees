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

void MorrisTraversal(Node *root)
{
    Node *current, *pre;

    if (root == nullptr)
        return;

    current = root;
    while (current != nullptr)
    {

        if (current->left == nullptr)
        {
            cout << current->data << " ";
            current = current->right;
        }
        else
        {
            pre = current->left;
            while (pre->right != nullptr && pre->right != current)
                pre = pre->right;

            if (pre->right == nullptr)
            {
                cout << current->data << " ";
                pre->right = current;
                current = current->left;
            }

            else
            {
                pre->right = nullptr;

                current = current->right;
            }
        }
    }
}

int main()
{
    Node *root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    MorrisTraversal(root);

    return 0;
}
