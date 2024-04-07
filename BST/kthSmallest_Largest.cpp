#include "BST.h"

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
