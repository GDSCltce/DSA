#include "BinaryTree.h"

void markParents(Node *root, map<Node *, Node *> &parent_track)
{
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr->left)
        {
            parent_track[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right)
        {
            parent_track[curr->right] = curr;
            q.push(curr->right);
        }
    }
}

vector<int> distanceK(Node *root, Node *target, int k)
{
    map<Node *, Node *> parent_track;
    markParents(root, parent_track);
    debug(parent_track);
    map<Node *, bool> visited;
    queue<Node *> q;
    q.push(target);
    visited[target] = true;
    int cur_level = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (cur_level++ == k)
            break;
        for (int i = 0; i < size; i++)
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left && !visited[curr->left])
            {
                q.push(curr->left);
                visited[curr->left] = 1;
            }
            if (curr->right && !visited[curr->right])
            {
                q.push(curr->right);
                visited[curr->right] = 1;
            }
            if (parent_track[curr] && !visited[parent_track[curr]])
            {
                q.push(parent_track[curr]);
                visited[parent_track[curr]] = 1;
            }
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        ans.emplace_back(curr->val);
    }
    return ans;
}

int main()
{
    inout();
    Node *root1 = new Node(3);
    root1->left = new Node(5);
    root1->right = new Node(1);
    root1->left->left = new Node(6);
    root1->left->right = new Node(2);
    root1->left->right->left = new Node(7);
    root1->left->right->right = new Node(1);
    root1->right->left = new Node(0);
    root1->right->right = new Node(8);
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

    printTree(root1);
    vector<int> ans = distanceK(root1, root1->left, 2);
    printArr(ans);
}
