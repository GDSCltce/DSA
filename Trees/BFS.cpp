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

// Line-by-line
vector<vector<int>> printlevel(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> lvl;

        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (curr->left)
            {
                q.push(curr->left);
            }
            if (curr->right)
            {
                q.push(curr->right);
            }
            // cout << curr->val << " ";
            lvl.emplace_back(curr->val);
        }
        // cout << "\n";
        ans.push_back(lvl);
    }
    return ans;
}

void printlvl(TreeNode *root)
{
    if (root == NULL)
        return;

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    while (q.size() > 1)
    {
        TreeNode *curr = q.front();
        q.pop();
        if (curr == NULL)
        {
            cout << "\n";
            q.push(NULL);
            continue;
        }
        cout << curr->val << " ";

        if (curr->left)
            q.push(curr->left);

        if (curr->right)
            q.push(curr->right);
    }
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

    int h = treeHeight(root);
    for (int i = 0; i < h; i++)
    {
        printKth(root, i);
    }

    // printlevel(root);
    // printKth(root, 3);
    cout << "\n";
    printlvl(root);
    return 0;
}