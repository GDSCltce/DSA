#include "BinaryTree.h"

Node *getParents(Node *root, map<Node *, Node *> &parent_track, int start)
{
    queue<Node *> q;
    Node *ans;
    q.push(root);
    while (!q.empty())
    {
        Node *curr = q.front();
        q.pop();
        if (curr->val == start)
            ans = curr;
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
    return ans;
}

int findMaxDistance(map<Node *, Node *> &parent_track, Node *target)
{
    queue<Node *> q;
    q.push(target);
    map<Node *, int> visited;
    visited[target] = 1;
    int maxi = 0;
    while (!q.empty())
    {
        int sz = q.size();
        bool fl = 0;
        for (int i = 0; i < sz; i++)
        {
            auto curr = q.front();
            q.pop();
            if (curr->left && !visited[curr->left])
            {
                fl = 1;
                visited[curr->left] = 1;
                q.push(curr->left);
            }
            if (curr->right && !visited[curr->right])
            {
                fl = 1;
                visited[curr->right] = 1;
                q.push(curr->right);
            }
            if (parent_track[curr] && !visited[parent_track[curr]])
            {
                fl = 1;
                visited[parent_track[curr]] = 1;
                q.push(parent_track[curr]);
            }
        }
        if (fl)
            maxi++;
    }
    return maxi;
}

int timeToBurnTree(Node *root, int start)
{
    map<Node *, Node *> parent_track;
    Node *target = getParents(root, parent_track, start);
    // debug(parent_track);
    int maxi = findMaxDistance(parent_track, target);
    return maxi;
}

int main()
{
    Node *root1 = new Node(1);
    root1->left = new Node(2);
    root1->right = new Node(3);
    root1->left->left = new Node(4);
    root1->left->left->right = new Node(7);
    root1->right->left = new Node(5);
    root1->right->right = new Node(6);
    // root1->left->right = new Node(5);
    // root1->left->right->left = new Node(6);
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

    cout << timeToBurnTree(root1, 2);
}