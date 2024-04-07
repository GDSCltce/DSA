#include "BinaryTree.h"

bool isLeaf(Node *root)
{
    return (!root->right && !root->left);
}

void addLeftBoundary(Node *root, vector<int> &ans)
{
    Node *cur = root->left;
    while (cur)
    {
        if (!isLeaf(cur))
            ans.emplace_back(cur->val);
        if (cur->left)
            cur = cur->left;
        else
            cur = cur->right;
    }
}

void addRightBoundary(Node *root, vector<int> &ans)
{
    Node *cur = root->right;
    vector<int> temp;
    while (cur)
    {
        if (!isLeaf(cur))
            temp.emplace_back(cur->val);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    for (int i = (int)temp.size() - 1; i >= 0; i--)
    {
        ans.emplace_back(temp[i]);
    }
}

void addLeaves(Node *root, vector<int> &ans)
{
    if (isLeaf(root))
    {
        ans.emplace_back(root->val);
        return;
    }
    if (root->left)
        addLeaves(root->left, ans);
    if (root->right)
        addLeaves(root->right, ans);
}

vector<int> solve(Node *root)
{
    vector<int> ans;
    if (!root)
        return ans;
    if (!isLeaf(root))
        ans.push_back(root->val);
    addRightBoundary(root, ans);
    addLeaves(root, ans);
    addLeftBoundary(root, ans);
    return ans;
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
    // root
    Node *root = new Node(20);
    root->left = new Node(8);
    root->right = new Node(12);
    root->left->left = new Node(3);
    root->left->right = new Node(5);
    root->right->left = new Node(10);
    root->right->right = new Node(2);
    root->left->right->left = new Node(2);
    root->left->right->right = new Node(3);
    root->right->left->right = new Node(10);
    root->right->left->right->right = new Node(14);
    root->right->left->right->left = new Node(1);

    vector<int> ans = solve(root);
    printTree(root);
    printArr(ans);
}