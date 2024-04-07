#ifndef BST_H
#define BST_H
#include <bits/stdc++.h>
using namespace std;

#define debug(x)                    \
    cout << #x << " = ", _print(x); \
    cout << endl;
struct Node
{
    int val;
    Node *left, *right;
    Node(int val)
    {
        this->val = val;
        this->left = NULL;
        this->right = NULL;
    }
    Node(int x, Node *left, Node *right) : val(x), left(left), right(right) {}
};
// DEBUG
void _print(int t) { cout << t; }
void _print(Node *t) { cout << t->val; }
void _print(string t) { cout << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T>
void _print(set<T> v);
template <class T, class V>
void _print(map<T, V> v);
template <class T>
void _print(multiset<T> v);
template <class T, class V>
void _print(pair<T, V> p) { cout << "{", _print(p.first), cout << " ,", _print(p.second), cout << "}\n"; }
template <class T>
void _print(vector<T> v)
{
    cout << "[ ";
    for (T i : v)
        _print(i), cout << ", ";
    cout << "]";
}
template <class T>
void _print(set<T> v)
{
    cout << "[ ";
    for (T i : v)
        _print(i), cout << " ";
    cout << "]";
}
template <class T>
void _print(multiset<T> v)
{
    cout << "[ ";
    for (T i : v)
        _print(i), cout << " ";
    cout << "]";
}
template <class T, class V>
void _print(map<T, V> v)
{
    cout << "[\n";
    for (auto i : v)
        _print(i), cout << " ";
    cout << "]";
}

void printTreeh(Node *root, int space = 0, bool side = true)
{
    if (root == NULL)
        return;

    space++;
    printTreeh(root->right, space, true);
    for (int i = 1; i < space; i++)
    {
        cout << "    ";
    }
    if (side == true)
        cout << "/ ";
    else
        cout << "\\ ";
    cout << root->val << endl;

    printTreeh(root->left, space, false);
}
void printTree(Node *root)
{
    cout << "------------------------------\n";
    printTreeh(root);
    cout << "------------------------------\n";
}

Node *insert(Node *root, int key)
{
    Node *new_node = new Node(key), *parent = NULL, *curr = root;
    while (curr)
    {
        parent = curr;
        if (curr->val > key)
        {
            curr = curr->left;
        }
        else if (curr->val < key)
        {
            curr = curr->right;
        }
        else
        {
            return root;
        }
    }

    if (parent == NULL)
    {
        return new_node;
    }
    if (parent->val > key)
    {
        parent->left = new_node;
    }
    else
    {
        parent->right = new_node;
    }
    return root;
}

Node *getSucccessor(Node *root)
{
    while (root && root->left)
        root = root->left;

    return root;
}

Node *helper(Node *root)
{
    if (root->left == NULL)
    {
        return root->right;
    }
    else if (root->right == NULL)
    {
        return root->left;
    }
    Node *succ = getSucccessor(root->right);
    succ->left = root->left;
    return root->right;
}

Node *deleteNode(Node *root, int key)
{
    if (root == NULL)
        return NULL;
    if (root->val == key)
    {
        return helper(root);
    }
    Node *dummy = root;
    while (root)
    {
        if (root->val > key)
        {
            if (root->left && root->left->val == key)
            {
                root->left = helper(root->left);
                break;
            }
            else
            {
                root = root->left;
            }
        }
        else
        {
            if (root->right && root->right->val == key)
            {
                root->right = helper(root->right);
                break;
            }
            else
            {
                root = root->right;
            }
        }
    }
    return dummy;
}

#endif