#include "BinaryTree.h"

Node *buildTreeHelper(vector<int> &inorder,
                      vector<int> &postorder,
                      map<int, int> &mp,
                      int ist, int ied,
                      int pst, int ped)
{
    if (pst > ped || ist > ied)
        return NULL;
    Node *root = new Node(postorder[ped]);

    int inIDX = mp[postorder[ped]];
    int numLeft = inIDX - ist;
    root->left = buildTreeHelper(inorder, postorder,
                                 mp, ist, inIDX - 1,
                                 pst, pst + numLeft - 1);

    root->right = buildTreeHelper(inorder, postorder,
                                  mp, inIDX + 1, ied,
                                  pst + numLeft, ped - 1);
    return root;
}

Node *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    map<int, int> mp;
    for (int i = 0; i < inorder.size(); i++)
    {
        mp[inorder[i]] = i;
    }
    return buildTreeHelper(inorder, postorder, mp, 0, inorder.size() - 1, 0, postorder.size() - 1);
}

int main()
{
    // inout();
    int n;
    cin >> n;
    vector<int> in(n);
    vector<int> post(n);

    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> post[i];
    }
    Node *root1 = new Node(10);
    root1->left = new Node(20);
    root1->right = new Node(30);
    root1->left->left = new Node(40);
    root1->left->right = new Node(50);
    root1->right->left = new Node(60);
    printTree(root1);
    // in_order(root1);
    // post_order(root1);
    // 40 20 50 10 60 30 40 50 20 60 30 10
    Node *croot1 = buildTree(in, post);
    printTree(croot1);
}