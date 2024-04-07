#include <iostream>
#include <vector>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void inout()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif
}

int treeHeight(TreeNode *root)
{
    if (root == NULL)
        return 0;
    return max(treeHeight(root->left), treeHeight(root->right)) + 1;
}

void printKth(TreeNode *root, int k)
{
    if (root == NULL || k < 0)
        return;
    if (k == 0)
    {
        cout << root->val << " ";
        return;
    }
    printKth(root->left, k - 1);
    printKth(root->right, k - 1);
}

int main()
{
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);
    root->right->right->right = new TreeNode(10);

    // TreeNode *root = new TreeNode(10);
    // root->left = new TreeNode(20);
    // root->right = new TreeNode(30);
    // root->left->left = new TreeNode(40);
    // root->left->right = new TreeNode(50);
    // root->right->right = new TreeNode(70);

    // TreeNode *root = new TreeNode(10);
    // root->left = new TreeNode(6);
    // root->right = new TreeNode(8);
    // root->right->right = new TreeNode(7);
    // root->right->right->left = new TreeNode(11);
    // root->right->right->right = new TreeNode(12);

    // TreeNode *root = new TreeNode(10);
    // root->left = new TreeNode(20);
    // root->left->left = new TreeNode(30);

    cout << treeHeight(root);
    printKth(root, 3);
    return 0;
}