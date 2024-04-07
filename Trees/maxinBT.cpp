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

int maxofBT(TreeNode *root)
{
    if (root == NULL)
    {
        return INT_MIN;
    }
    return max(root->val, max(maxofBT(root->left), maxofBT(root->right)));
}

int maxofBTi(TreeNode *root)
{
    int mx = INT_MIN;
    if (root == NULL)
        return mx;
    queue<TreeNode *> q;
    q.push(root);
    mx = root->val;
    int cnt = 0;
    q.push(NULL);
    while (q.size() > 1)
    {
        TreeNode *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            q.push(NULL);
            continue;
        }
        mx = max(curr->val, mx);
        cnt++;

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }
    return mx;
}

int main()
{
    inout();
    TreeNode *root = new TreeNode(1);
    // root->left = new TreeNode(2);
    // root->right = new TreeNode(3);
    // root->left->left = new TreeNode(44);
    // root->left->right = new TreeNode(5);
    // root->left->right->left = new TreeNode(6);
    // root->right->left = new TreeNode(7);
    // root->right->right = new TreeNode(8);
    // root->right->right->left = new TreeNode(9);
    // root->right->right->right = new TreeNode(10);

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

    cout << maxofBT(root) << " ";
    cout << maxofBTi(root);
    return 0;
}