#include "BinaryTree.h"

void diameterOFTree(Node *root, int &mx)
{
    if (root == NULL)
        return;

    int lh = tree_Height(root->left);
    int rh = tree_Height(root->right);

    mx = max(mx, lh + rh);

    diameterOFTree(root->left, mx);
    diameterOFTree(root->right, mx);
    return;
}

int diameterOFTreeON(Node *root, int &mx)
{
    if (root == NULL)
        return 0;
    int lh = diameterOFTreeON(root->left, mx);
    int rh = diameterOFTreeON(root->right, mx);

    mx = max(mx, lh + rh);

    return 1 + max(lh, rh);
}

int solve(Node *root)
{
    int mx = 0;
    diameterOFTreeON(root, mx);
    return mx;
}

int main()
{
    inout();
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->right = new Node(5);
    root1->left->right->left = new Node(6);
    root1->right->left = new Node(7);
    root1->right->right = new Node(8);
    root1->right->right->left = new Node(9);
    root1->right->right->right = new Node(10);
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
    // Node *root = new Node(10);
    // root->left = new Node(20);
    // root->right = new Node(30);
    // root->left->right = new Node(40);
    // root->left->right->left = new Node(60);
    // root->left->right->right = new Node(70);
    // root->right->left = new Node(50);
    // root->right->left->left = new Node(80);
    // root->right->left->right = new Node(90);
    // root->right->left->left->right = new Node(100);
    printTree(root1);
    cout << solve(root1);
}