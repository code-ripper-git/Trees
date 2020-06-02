
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

void BToDLL(Node *root, Node *&head_ref)
{
    if (root == nullptr)
        return;

    BToDLL(root->right, head_ref);

    root->right = head_ref;
    if (head_ref != nullptr)
        head_ref->left = root;

    head_ref = root;

    BToDLL(root->left, head_ref);
}

void printList(Node *head)
{
    cout << "Extracted Double Linked list is:" << endl;
    while (head)
    {
        cout << head->data << " ";
        head = head->right;
    }
}

int main()
{
    Node *root = new Node(5);
    root->left = new Node(3);
    root->right = new Node(6);
    root->left->left = new Node(1);
    root->left->right = new Node(4);
    root->right->right = new Node(8);
    root->left->left->left = new Node(0);
    root->left->left->right = new Node(2);
    root->right->right->left = new Node(7);
    root->right->right->right = new Node(9);

    Node *head = nullptr;
    BToDLL(root, head);

    printList(head);
    cout << endl;
    return 0;
}
