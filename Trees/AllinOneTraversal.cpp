#include "BinaryTree.h"

#define endl '\n'
#define ll long long int
#define ld long double
#define ull unsigned long long
#define mod 1000000007
#define PI 3.141592653589793238462
#define sz(x) ((int)(x).size())
#define gri greater<int>()
#define all(x) (x).begin(), (x).end()
#define debug(x)                    \
    cout << #x << " = ", _print(x); \
    cout << endl;
/*-------------------ASIMARIES--------------------*/
void _print(int t) { cout << t; }
void _print(ll t) { cout << t; }
void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
void _print(ld t) { cout << t; }
void _print(double t) { cout << t; }
void _print(ull t) { cout << t; }
template <class T, class V>
void _print(pair<T, V> p);
template <class T>
void _print(vector<T> v);
template <class T, class V>
void _print(pair<T, V> p) { cout << "{", _print(p.first), cout << " ,", _print(p.second), cout << "}"; }
template <class T>
void _print(vector<T> v)
{
    cout << "[ ";
    for (T i : v)
        _print(i), cout << " ";
    cout << "]";
}

vector<vector<int>> getTreeTraversal(Node *root)
{
    stack<pair<Node *, int>> stk;
    stk.push({root, 1});
    vector<int> pre, in, post;
    if (root == NULL)
        return {in, pre, post};
    while (!stk.empty())
    {
        auto it = stk.top();
        stk.pop();

        if (it.second == 1)
        {
            pre.emplace_back(it.first->val);
            it.second++;
            stk.push(it);
            if (it.first->left)
            {
                stk.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.emplace_back(it.first->val);
            it.second++;
            stk.push(it);
            if (it.first->right)
            {
                stk.push({it.first->right, 1});
            }
        }
        else
        {
            post.emplace_back(it.first->val);
        }
    }
    return {in, pre, post};
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

    vector<vector<int>> ans = getTreeTraversal(root1);
    debug(ans);
}