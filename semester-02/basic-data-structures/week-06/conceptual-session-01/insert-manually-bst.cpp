#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int val;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
};
void levelOrder(Node *root)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        // 1. ber kore ana
        Node *f = q.front();
        q.pop();
        // 2. jabotiyo kaj
        cout << f->val << " ";
        // 3. tar children rakha
        if (f->left)
        {
            q.push(f->left);
        }
        if (f->right)
        {
            q.push(f->right);
        }
    }
}
void insert(Node *&root, int v)
{
    Node *newNode = new Node(v);
    if (root == NULL)
    {
        root = newNode;
        return;
    }
    Node *prev = NULL;
    Node *curr = root;
    while (curr != NULL)
    {
        if (v < curr->val)
        {
            // insert left subtree
            prev = curr;
            curr = curr->left;
        }
        else if (v > curr->val)
        {
            // insert right subtree
            prev = curr;
            curr = curr->right;
        }
    }
    // connection
    if (v < prev->val)
    {
        prev->left = newNode;
    }
    else if (v > prev->val)
    {
        prev->right = newNode;
    }
}
int main()
{
    Node *root = NULL;
    int val;
    while (1)
    {

        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert(root, val);
    }

    levelOrder(root);
    return 0;
}