#include "BinaryTree.h"

vector<int> preorderI(Node *root)
{
    vector<int> preorder;
    stack<Node *> stk;
    stk.push(root);
    while (!stk.empty())
    {
        Node *curr = stk.top();
        stk.pop();
        preorder.emplace_back(curr->val);
        if (curr->right)
            stk.push(curr->right);
        if (curr->left)
            stk.push(curr->left);
    }
    return preorder;
}

vector<int> inorderI(Node *root)
{
    vector<int> inorder;
    if (root == NULL)
        return inorder;
    stack<Node *> stk;
    Node *curr = root;
    while (true)
    {
        if (curr)
        {
            stk.push(curr);
            curr = curr->left;
        }
        else
        {
            if (stk.empty())
                break;
            curr = stk.top();
            stk.pop();
            inorder.emplace_back(curr->val);
            curr = curr->right;
        }
    }
    return inorder;
}

vector<int> postorder2stkI(Node *root)
{
    vector<int> postorder;
    if (root == NULL)
        return postorder;
    stack<Node *> stk1;
    stack<Node *> stk2;
    stk1.push(root);
    while (!stk1.empty())
    {
        Node *curr = stk1.top();
        stk1.pop();
        stk2.push(curr);
        if (curr->left)
            stk1.push(curr->left);
        if (curr->right)
            stk1.push(curr->right);
    }
    while (!stk2.empty())
    {
        postorder.emplace_back(stk2.top()->val);
        stk2.pop();
    }
    return postorder;
}

vector<int> postorderI(Node *root)
{
    vector<int> postorder;
    if (root == NULL)
        return postorder;
    stack<Node *> stk;
    Node *curr = root;
    while (curr || !stk.empty())
    {
        if (curr)
        {
            stk.push(curr);
            curr = curr->left;
        }
        else
        {
            Node *temp = stk.top()->right;
            if (temp == NULL)
            {
                temp = stk.top();
                stk.pop();
                postorder.emplace_back(temp->val);
                while (!stk.empty() && temp == stk.top()->right)
                {
                    temp = stk.top();
                    stk.pop();
                    postorder.emplace_back(temp->val);
                }
            }
            else
            {
                curr = temp;
            }
        }
    }
    return postorder;
}

int main()
{
    inout();
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(7);
    root1->left->left = new Node(3);
    root1->left->right = new Node(4);
    root1->left->right->left = new Node(5);
    root1->left->right->right = new Node(6);
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
    vector<int> preorder = preorderI(root1);
    // printArr(preorder);
    vector<int> inorder = inorderI(root1);
    printArr(inorder);
    vector<int> postorder = postorderI(root1);
    printArr(postorder);
}