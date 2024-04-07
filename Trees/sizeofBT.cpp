#include <iostream>
#include <vector>
#include <queue>
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

int sizeofBT(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    return sizeofBT(root->left) + sizeofBT(root->right) + 1;
}

int printlvl(TreeNode *root)
{
    if (root == NULL)
        return 0;

    queue<TreeNode *> q;
    q.push(root);
    int cnt = 0;
    q.push(NULL);
    while (q.size() > 1)
    {
        TreeNode *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            // cout << "\n";
            q.push(NULL);
            continue;
        }
        // cout << curr->val << " ";
        cnt++;

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }
    return cnt;
}

int main()
{
    inout();
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

    cout << sizeofBT(root) << " ";
    cout << printlvl(root);
    return 0;
}