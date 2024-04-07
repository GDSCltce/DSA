#include <iostream>
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

// class Tree
// {
//     TreeNode *root;
//     int size;
// public:
//     Tree(T x)
//     {
//         root = new TreeNode(x);
//         // root->data = x;
//         size = 1;
//     }
//     void push_left(TreeNode * node, T x)
//     {
//         node->left = new TreeNode(x);
//     }
//     void push_right(TreeNode * node, T x)
//     {
//         node->right = new TreeNode(x);
//     }
// };

void preorder(TreeNode *root)
{
    if (root == NULL)
        return;

    cout << root->val << ' ';
    preorder(root->left);
    preorder(root->right);
}

void inorder(TreeNode *root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->val << ' ';
    inorder(root->right);
}

void postorder(TreeNode *root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->val << ' ';
}

void inout()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif
}

void print(TreeNode *root, int space, bool side)
{
    if (root == NULL)
        return;

    space += 5;
    print(root->right, space, true);
    for (int i = 0; i < space; i++)
    {
        cout << " ";
    }
    if (side)
        cout << "/ ";
    else
        cout << "\\ ";
    cout << root->val << endl;

    print(root->left, space, false);
}

int main()
{
    // inout();
    // TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(4);
    // root->left->right = new TreeNode(5);
    // root->left->right->left = new TreeNode(6);
    // root->right->left = new TreeNode(7);
    // root->right->right = new TreeNode(8);
    // root->right->right->left = new TreeNode(9);
    // root->right->right->right = new TreeNode(10);

    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(20);
    root->right = new TreeNode(30);
    root->left->right = new TreeNode(40);
    root->left->right->left = new TreeNode(60);
    root->left->right->right = new TreeNode(70);
    root->right->left = new TreeNode(50);
    root->right->left->left = new TreeNode(80);
    root->right->left->right = new TreeNode(90);
    root->right->left->left->right = new TreeNode(100);

    preorder(root);
    cout << '\n';
    inorder(root);
    cout << '\n';
    postorder(root);
    cout << '\n';
    print(root, 0, true);
    return 0;
}

