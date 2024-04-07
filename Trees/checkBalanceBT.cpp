#include "BinaryTree.h"

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return max(height(root->left), height(root->right)) + 1;
}

bool isBalanced(Node *root)
{
    if (root == NULL)
        return true;

    int left_height = height(root->left);
    int right_height = height(root->right);
    if (abs(left_height - right_height) < 2 && isBalanced(root->left) && isBalanced(root->right))
        return true;
    else
        return false;
}

int isBalancedi(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = isBalancedi(root->left);
    if (lh == -1)
        return -1;

    int rh = isBalancedi(root->right);
    if (rh == -1)
        return -1;
        
    if (abs(lh - rh) < 2)
        return max(lh, rh) + 1;
    else
        return -1;
}

int main()
{
    inout();
    // Node *root1 = new Node(1);
    // root1->left = new Node(2);
    // root1->right = new Node(3);
    // root1->left->left = new Node(4);
    // root1->left->right = new Node(5);
    // root1->left->right->left = new Node(6);
    // root1->right->left = new Node(7);
    // root1->right->right = new Node(8);
    // root1->right->right->left = new Node(9);
    // root1->right->right->right = new Node(10);
    // // root2
    // Node *root2 = new Node(70);
    // // root3
    // Node *root3 = new Node(10);
    // root3->left = new Node(6);
    // root3->right = new Node(8);
    // root3->right->right = new Node(7);
    // root3->right->right->left = new Node(11);
    // root3->right->right->right = new Node(12);
    // // root4
    // Node *root4 = new Node(10);
    // root4->left = new Node(20);
    // root4->left->left = new Node(30);
    // // root
    // Node *root = new Node(20);
    // root->left = new Node(8);
    // root->right = new Node(12);
    // root->left->left = new Node(3);
    // root->left->right = new Node(5);
    // root->right->left = new Node(10);
    // root->right->right = new Node(2);
    // root->left->right->left = new Node(2);
    // root->left->right->right = new Node(3);
    // root->right->left->right = new Node(10);
    // root->right->left->right->right = new Node(14);
    // root->right->left->right->left = new Node(1);
    // // root
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->right = new Node(40);
    root->left->right->left = new Node(60);
    root->left->right->right = new Node(70);
    root->right->left = new Node(50);
    root->right->left->left = new Node(80);
    root->right->left->right = new Node(90);
    root->right->left->left->right = new Node(100);

    cout << height(root);

    if (isBalancedi(root)!= -1)
        cout << "yes";
    else
        cout << "no";
}