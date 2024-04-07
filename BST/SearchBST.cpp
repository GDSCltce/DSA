#include "BST.h"

Node *floort(Node *root, int key)
{
    Node *res = NULL;
    while (root)
    {
        if (root->val == key)
        {
            return root;
        }
        else if (root->val > key)
        {
            root = root->left;
        }
        else
        {
            res = root;
            root = root->right;
        }
    }
    return res;
}

Node *ceilt(Node *root, int key)
{
    Node *res = NULL;
    while (root)
    {
        if (root->val == key)
        {
            return root;
        }
        if (root->val < key)
        {
            root = root->right;
        }
        else
        {
            res = root;
            root = root->left;
        }
    }
    return res;
}

void KthSmallestHelper(Node *root, int k, int &cnt, int &ans)
{
    if (k > cnt)
    {
        if (root->left)
            KthSmallestHelper(root->left, k, cnt, ans);
        if (k == ++cnt)
        {
            ans = root->val;
            return;
        }
        if (root->right)
            KthSmallestHelper(root->right, k, cnt, ans);
    }
    return;
}

int kthSmallest(Node *root, int k)
{
    int cnt = 0;
    int ans = -1;
    KthSmallestHelper(root, k, cnt, ans);
    return ans;
}

void kthLargestHelper(Node *root, int k, int &cnt, int &ans)
{
    if (k > cnt)
    {
        if (root->right)
            kthLargestHelper(root->right, k, cnt, ans);
        if (k == ++cnt)
        {
            ans = root->val;
            return;
        }
        if (root->left)
            kthLargestHelper(root->left, k, cnt, ans);
    }
}

int kthLargest(Node *root, int k)
{
    int cnt = 0;
    int ans = -1;
    kthLargestHelper(root, k, cnt, ans);
    return ans;
}

int main(int argc, char const *argv[])
{
    Node *root = NULL;
    int x;
    for (int i = 0; i < 10; i++)
    {
        cin >> x;
        root = insert(root, x);
    }
    printTree(root);
    for (int i = 0; i < 3; i++)
    {
        cin >> x;
        // root = deleteNode(root, x);
        // printTree(root);
        cout << ceilt(root, x)->val << endl;
    }
    cout << kthSmallest(root, 3) << endl;
    cout << kthLargest(root, 5);
    return 0;
}
