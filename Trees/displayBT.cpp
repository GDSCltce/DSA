#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define count 5;
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

void display(Node *root)
{
    if (root == NULL)
        return;
    string str = "";
    str += root->left == NULL ? "." : to_string(root->left->data);
    str += " <- " + to_string(root->data) + " -> ";
    str += root->right == NULL ? "." : to_string(root->right->data);
    cout << str;

    display(root->left);
    display(root->right);
}

void print(Node *root, int space, bool side)
{
    if (root == NULL)
        return;

    space += count;
    print(root->right, space, true);
    // cout << endl;
    for (int i = 0; i < space; i++)
    {
        cout << " ";
    }
    if (side)
        cout << "/>";
    else
        cout << "\\>";
    cout << root->data << endl;

    print(root->left, space, false);
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

    // Node *root = new Node(70);

    // Node *root = new Node(10);
    // root->left = new Node(6);
    // root->right = new Node(8);
    // root->right->right = new Node(7);
    // root->right->right->left = new Node(11);
    // root->right->right->right = new Node(12);

    // Node *root = new Node(10);
    // root->left = new Node(20);
    // root->left->left = new Node(30);
    /*

8 <- 20 -> 123 
<- 8 -> 5. <- 3 -> .2 <- 5 -> 3. <- 2 -> .. <- 3 -> .10 <- 12 -> 2. <- 10 -> 10. <- 10 -> 14. <- 14 -> .. <- 2 -> .
*/
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

    // display(root);
    cout << endl;
    print(root, 0, true);
    return 0;
}
