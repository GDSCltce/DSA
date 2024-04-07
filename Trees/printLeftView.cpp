#include <iostream>
#include <vector>
#include <queue>
using namespace std;
template <typename T>
void printArr(vector<T> &a)
{
    for (auto i : a)
        cout << i << ' ';
    cout << "\n";
}

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

vector<int> leftView(TreeNode *root, int level, vector<int> &ans)
{
    static int maxlevel = 0;
    if (root == NULL)
    {
        return ans;
    }
    if (ans.size() < level)
    {
        // cout << root->val << ' ';
        ans.emplace_back(root->val);
        maxlevel = level;
    }
    leftView(root->left, level + 1, ans);
    leftView(root->right, level + 1, ans);
    return ans;
}

void leftViewi(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int cnt = q.size();
        for (int i = 0; i < cnt; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (i == 0)
            {
                // cout << curr->val << " ";
                ans.emplace_back(curr->val);
            }
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return;
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

    // TreeNode *root = new TreeeNode(70);

    // TreeNode *root = new TreeNode(10);
    // root->left = new TreeNode(6);
    // root->right = new TreeNode(8);
    // root->right->right = new TreeNode(7);
    // root->right->right->left = new TreeNode(11);
    // root->right->right->right = new TreeNode(12);

    // TreeNode *root = new TreeNode(10);
    // root->left = new TreeNode(20);
    // root->left->left = new TreeNode(30);
    
    
    vector<int> ans;
    leftView(root, 1, ans);
    printArr(ans);
    vector<int> ans1;
    leftViewi(root, ans1);
    printArr(ans1);
    // cout << printlvl(root);
    return 0;
}