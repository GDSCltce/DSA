#include "BST.h"

Node *build(vector<int> &a, int &i, int bound)
{
    if (i == a.size() || a[i] > bound)
        return NULL;
    Node *root = new Node(a[i++]);
    root->left = build(a, i, root->val);
    root->right = build(a, i, bound);
    return root;
}

Node *bstFromPreorder(vector<int> &a)
{
    int i = 0;
    return build(a, i, INT_MAX);
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    int x;
    vector<int> a;
    for (int i = 0; i < 10; i++)
    {
        cin >> x;
        // root = insert(root, x);
        a.push_back(x);
    }
    root = bstFromPreorder(a);
    printTree(root);
    return 0;
}