#ifndef Binary_Tree_H
#define Binary_Tree_H

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

template <typename T>
void printArr(vector<T> &a)
{
    for (auto i : a)
        cout << i << ' ';
    cout << "\n";
}

void inout()
{
#ifndef ONLINE_JUDGE
    freopen("in.in", "r", stdin);
    // freopen("out.in", "w", stdout);
#endif
}

// printTree(root, 0, true)
void printTree(Node *root, int space = 0, bool side = true)
{
    if (root == NULL)
        return;

    space++;
    printTree(root->right, space, true);
    for (int i = 1; i < space; i++)
    {
        printf("    ");
    }
    if (side == true)
        printf("/ ");
    else
        printf("\\ ");
    printf("%d\n", root->val);

    printTree(root->left, space, false);
}

void pre_order(Node *root)
{
    if (root == NULL)
        return;

    cout << root->val << ' ';
    pre_order(root->left);
    pre_order(root->right);
}

void in_order(Node *root)
{
    if (root == NULL)
        return;

    in_order(root->left);
    cout << root->val << ' ';
    in_order(root->right);
}

void post_order(Node *root)
{
    if (root == NULL)
        return;

    post_order(root->left);
    post_order(root->right);
    cout << root->val << ' ';
}

int tree_Height(Node *root)
{
    if (root == NULL)
        return 0;
    return max(tree_Height(root->left), tree_Height(root->right)) + 1;
}

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
void _print(pair<T, V> p) { cout << "{", _print(p.first), cout << " ,", _print(p.second), cout << "}"; }
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
        _print(i), cout << "\n";
    cout << "]";
}

#endif