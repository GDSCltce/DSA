#include "BST.h"

bool isBST(Node *root, int mn = INT_MIN, int mx = INT_MAX)
{
    if (root == NULL)
        return true;
    if (root->val >= mx || root->val <= mn)
        return false;
    return isBST(root->left, mn, root->val) && isBST(root->right, root->val, mx);
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    int x;
    for (int i = 0; i < 10; i++)
    {
        cin >> x;
        root = insert(root, x);
    }
    printTree(root);
    cout << isBST(root);
    return 0;
}