#include "BST.h"

Node *LCABST(Node *root, Node *p, Node *q)
{
    while (root)
    {
        if (root->val < p->val && root->val < q->val)
        {
            root = root->right;
        }
        else if (root->val > p->val && root->val > q->val)
        {
            root = root->left;
        }
        else
        {
            return root;
        }
    }
    return root;
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
    cout << LCABST(root, root->right->left->right, root->right->right)->val;
    return 0;
}