#include "BinaryTree.h"

vector<int> topView(Node *root)
{
    vector<int> ans;
    if (root == nullptr)
    {
        return ans;
    }
    map<int, int> mp;
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        Node *curr = it.first;
        int line = it.second;
        if (mp.find(line) == mp.end())
            mp[line] = curr->val;
        if (curr->left)
            q.push({curr->left, line - 1});
        if (curr->right)
            q.push({curr->right, line + 1});
    }

    for (auto i : mp)
    {
        ans.emplace_back(i.second);
    }
    return ans;
}

vector<int> bottomView(Node *root)
{
    vector<int> ans;
    if (root)
    {
        map<int, int> mp;
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            auto it = q.front();
            q.pop();
            mp[it.second] = it.first->val;
            if (it.first->left)
                q.push({it.first->left, it.second - 1});
            if (it.first->right)
                q.push({it.first->right, it.second + 1});
        }
        for (auto &i : mp)
        {
            ans.emplace_back(i.second);
        }
    }
    return ans;
}

void rightView(Node *root, vector<int> &ans, int level = 0)
{
    if (root == nullptr)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.emplace_back(root->val);
    }
    rightView(root->right, ans, level + 1);
    rightView(root->left, ans, level + 1);
}

void leftView(Node *root, vector<int> &ans, int level = 0)
{
    if (root == nullptr)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.emplace_back(root->val);
    }
    leftView(root->left, ans, level + 1);
    leftView(root->right, ans, level + 1);
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
    vector<int> ans = topView(root1);
    printArr(ans);
    ans = bottomView(root1);
    printArr(ans);

    vector<int> Right;
    rightView(root1, Right);
    printArr(Right);
    vector<int> Left;
    leftView(root1, Left);
    printArr(Left);
}