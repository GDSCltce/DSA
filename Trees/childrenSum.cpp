#include "BinaryTree.h"

// int isSumProperty(Node *root)
// {
//     int left_val = 0, right_val = 0;
//     if (root == NULL || (root->left == NULL && root->right == NULL))
//         return 1;
//     else
//     {
//         if (root->left != NULL)
//         {
//             left_val = root->left->val;
//         }
//         if (root->right != NULL)
//         {
//             right_val = root->right->val;
//         }
//         if ((root->val == left_val + right_val) &&
//             isSumProperty(root->left) && isSumProperty(root->right))
//         {
//             return 1;
//         }
//         else
//             return 0;
//     }
// }
// int isSumPropertyi(Node *root)
// {
//     queue<Node *> q;
//     q.push(root);
//     while (!q.empty())
//     {
//         Node *curr = q.front();
//         q.pop();
//         if (curr->left && curr->right)
//         {
//             if (curr->val != curr->left->val + curr->right->val)
//             {
//                 return false;
//             }
//             q.push(curr->left);
//             q.push(curr->right);
//         }
//         else if (!curr->left && curr->right)
//         {
//             if (curr->val != curr->right->val)
//             {
//                 return false;
//             }
//             q.push(curr->right);
//         }
//         else if (curr->left && !curr->right)
//         {
//             if (curr->val != curr->left->val)
//             {
//                 return false;
//             }
//             q.push(curr->left);
//         }
//     }
//     return true;
// }

void changeTree(Node *root)
{
    if (root == NULL)
        return;
    int child = 0;
    if (root->left)
        child += root->left->val;
    if (root->right)
        child += root->right->val;
    if (child >= root->val)
    {
        root->val = child;
    }
    else
    {
        if (root->left)
            root->left->val = root->val;
        else if (root->right)
            root->right->val = root->val;
    }
    changeTree(root->left);
    changeTree(root->right);

    int tot = 0;
    if (root->left)
        tot += root->left->val;
    if (root->right)
        tot += root->right->val;
    if (root->left or root->right)
        root->val = tot;
}

int main()
{
    // inout();
    // Node *root = new Node(1);
    // root->left = new Node(2);
    // root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->right = new Node(5);
    // root->left->right->left = new Node(6);
    // root->right->left = new Node(7);
    // root->right->right = new Node(8);
    // root->right->right->left = new Node(9);
    // root->right->right->right = new Node(10);
    // Node *root = new TreeeNode(70);
    // Node *root = new Node(10);
    // root->left = new Node(6);
    // root->right = new Node(8);
    // root->right->right = new Node(7);
    // root->right->right->left = new Node(11);
    // root->right->right->right = new Node(12);
    // Node *root = new Node(10);
    // root->left = new Node(20);
    // root->left->left = new Node(30);

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
    //

    return 0;
}