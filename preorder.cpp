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

Node *constructTree(int pre[], int size)
{
    vector<Node *> stack;
    Node *root = new Node(pre[0]);
    stack.push_back(root);
    Node *temp;
    for (int i = 1; i < size; ++i)
    {
        temp = nullptr;
        while (!stack.empty() && pre[i] > stack.back()->data)
        {
            temp = stack.back();
            stack.pop_back();
        }
        if (temp != nullptr)
        {
            temp->right = new Node(pre[i]);
            stack.push_back(temp->right);
        }
        else
        {
            stack.back()->left = new Node(pre[i]);
            stack.push_back(stack.back()->left);
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
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = sizeof(pre) / sizeof(pre[0]);

    Node *root = constructTree(pre, size);

    cout << "Inorder traversal of the constructed tree: \n";
    printInorder(root);

    return 0;
}
