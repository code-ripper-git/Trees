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

void issumtree(Node *root, bool &sumtree)
{
    sumtree = true;
    if (!root)
        return;
    queue<Node *> q;
    q.push(root);
    auto isleaf = [](Node *root) {
        if (!root->left && !root->right)
            return true;
        return false;
    };
    while (!q.empty())
    {
        Node *node = q.front();
        q.pop();
        int sum = 0;
        if (node->left)
        {
            if (isleaf(node->left))
            {
                sum += node->left->data;
            }
            else
            {
                q.push(node->left);
                sum += 2 * node->left->data;
            }
        }
        if (node->right)
        {
            if (isleaf(node->right))
            {
                sum += node->right->data;
            }
            else
            {
                q.push(node->right);
                sum += 2 * node->right->data;
            }
        }
        sumtree = sumtree && (node->data == sum);
        if (!sumtree)
            break;
    }
}
int main()
{
    Node *root = new Node(26);
    root->left = new Node(10);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(6);
    root->right->right = new Node(3);
    bool sumtree;
    issumtree(root, sumtree);
    if (sumtree)
        cout << "Is a sum tree" << endl;
    return 0;
}