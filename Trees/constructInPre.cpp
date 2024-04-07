#include "BinaryTree.h"

Node *buildTreeHelper(vector<int> &preorder, vector<int> &inorder, map<int, int> &mp, int &preIDX, int st, int ed)
{
    if (st > ed)
    {
        return NULL;
    }
    Node *new_node = new Node(preorder[preIDX++]);
    if (st == ed)
        return new_node;
    int inIDX = mp[new_node->val];

    new_node->left = buildTreeHelper(preorder, inorder, mp, preIDX, st, inIDX - 1);
    new_node->right = buildTreeHelper(preorder, inorder, mp, preIDX, inIDX + 1, ed);
    return new_node;
}

Node *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int preIDX = 0;
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    return buildTreeHelper(preorder, inorder, mp, preIDX, 0, inorder.size() - 1);
}

int main()
{
    // inout();
    int n;
    cin >> n;
    vector<int> in(n);
    vector<int> pre(n);

    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> pre[i];
    }
    Node *root1 = new Node(10);
    root1->left = new Node(20);
    root1->right = new Node(30);
    root1->left->left = new Node(40);
    root1->left->right = new Node(50);
    root1->right->left = new Node(60);
    // printTree(root1);
    // in_order(root1);
    // pre_order(root1);
    Node *croot1 = buildTree(pre, in);
    printTree(croot1);
}
