#include "BinaryTree.h"

vector<int> morrisTraversal(Node *root)
{
    vector<int> inorder;
    Node *curr = root;
    while (curr)
    {
        if (curr->left == NULL)
        {
            inorder.emplace_back(curr->val);
            curr = curr->right;
        }
        else
        {
            Node *prev = curr->left;
            while (prev->right &&)
            {
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);
    morrisTraversal(root);
    return 0;
}
