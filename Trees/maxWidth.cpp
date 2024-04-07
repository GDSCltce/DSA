#include "BinaryTree.h"

int max_width(Node *root)
{
    if (root == NULL)
        return 0;
    queue<Node *> q;
    q.push(root);
    int ans = 0;
    while (!q.empty())
    {
        int sz = q.size();
        ans = max(ans, sz);
        for (int i = 0; i < sz; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
        }
    }
    return ans;
}

int widthOfBinaryTree(Node *root)
{
    int ans = 0;
    if (root)
    {
        queue<pair<Node *, int>> q;
        q.push({root, 0});
        while (!q.empty())
        {
            int size = q.size();
            int mn = q.front().second;
            int l;
            for (int i = 0; i < size; i++)
            {
                int cur_id = q.front().second - mn;
                Node *curr = q.front().first;
                q.pop();
                if (i == size - 1)
                    l = cur_id;
                if (curr->left)
                    q.push({curr->left, cur_id * 2 + 1});
                if (curr->right)
                    q.push({curr->right, cur_id * 2 + 2});
            }
            ans = max(ans, l + 1);
        }
    }
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
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->right = new Node(40);
    root->left->right->left = new Node(60);
    root->left->right->right = new Node(70);
    root->right->left = new Node(50);
    root->right->left->left = new Node(80);
    root->right->left->right = new Node(90);
    root->right->left->left->right = new Node(100);

    cout << max_width(root);
}