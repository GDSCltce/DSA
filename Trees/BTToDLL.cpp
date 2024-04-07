#include "BinaryTree.h"

Node *BTtoDLL(Node *root)
{
    static Node *prev = NULL;
    if (root == NULL)
        return NULL;

    Node *head = BTtoDLL(root->left);
    if (prev)
    {
        root->left = prev;
        prev->right = root;
    }
    else
    {
        head = root;
    }
    prev = root;
    BTtoDLL(root->right);
    return head;
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

    
    Node *newDLL = BTtoDLL(root);
    for (Node *curr = newDLL; curr != NULL; curr = curr->right)
    {
        cout << curr->val << " ";
    }
}

/*#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printArr(vector<T> &a)
{
    for (auto i : a)
        cout << i << ' ';
    cout << "\n";
}

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

void inout()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    freopen("out.in", "w", stdout);
#endif
}

Node *BTToDLL(Node *root, Node *&prev)
{
    if (root == NULL)
    {
        return root;
    }
    Node *head = BTToDLL(root->left, prev);
    if (prev == NULL)
    {
        head = root;
    }
    else
    {
        root->left = prev;
        prev->right = root;
    }
    prev = root;
    BTToDLL(root->right, prev);
    return head;
}

void printDLL(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->right;
    }
    return;
}

int main()
{
    // inout();
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

    Node *root2 = new Node(70);

    Node *root3 = new Node(10);
    root3->left = new Node(6);
    root3->right = new Node(8);
    root3->right->right = new Node(7);
    root3->right->right->left = new Node(11);
    root3->right->right->right = new Node(12);

    Node *root4 = new Node(10);
    root4->left = new Node(20);
    root4->left->left = new Node(30);

    Node *root5 = new Node(20);
    root5->left = new Node(8);
    root5->right = new Node(12);
    root5->left->left = new Node(3);
    root5->left->right = new Node(5);
    root5->right->left = new Node(10);
    root5->right->right = new Node(2);
    root5->left->right->left = new Node(2);
    root5->left->right->right = new Node(3);
    root5->right->left->right = new Node(10);
    root5->right->left->right->right = new Node(14);
    root5->right->left->right->left = new Node(1);

    Node *prev = NULL;
    Node *head = BTToDLL(root5, prev);
    printDLL(head);

    return 0;
}
*/