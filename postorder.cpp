#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left, *right;
    Node(int data)
    {
        this->data = data;
        left = right = nullptr;
    }
};

Node *constructTree(int post[], int size)
{
    vector<Node *> stack;
    Node *root = new Node(post[size]);
    stack.push_back(root);
    Node *temp;
    for (int i = size - 1; i >= 0; i--)
    {
        temp = nullptr;
        while (!stack.empty() && post[i] < stack.back()->data)
        {
            temp = stack.back();
            stack.pop_back();
        }
        if (temp != nullptr)
        {
            temp->left = new Node(post[i]);
            stack.push_back(temp->left);
        }
        else
        {
            stack.back()->right = new Node(post[i]);
            stack.push_back(stack.back()->right);
        }
    }
    return root;
}

void printInorder(Node *node)
{
    if (node == nullptr)
        return;
    printInorder(node->left);
    cout << node->data << " ";
    printInorder(node->right);
}

int main()
{
    int post[] = {1, 7, 5, 50, 40, 10};
    int size = sizeof(post) / sizeof(post[0]);

    Node *root = constructTree(post, size - 1);

    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);

    return 0;
}
