#include "BinaryTree.h"

string serialize(Node *root)
{
    if (!root)
        return "";

    string s = "";
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *curNode = q.front();
        q.pop();
        if (curNode == NULL)
            s.append("#,");
        else
            s.append(to_string(curNode->val) + ',');
        if (curNode != NULL)
        {
            q.push(curNode->left);
            q.push(curNode->right);
        }
    }
    return s;
}
Node *deserialize(string data)
{
    if (data.size() == 0)
        return NULL;
    stringstream s(data);
    string str;
    getline(s, str, ',');
    Node *root = new Node(stoi(str));
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {

        Node *curr = q.front();
        q.pop();

        getline(s, str, ',');
        if (str == "#")
        {
            curr->left = NULL;
        }
        else
        {
            Node *l = new Node(stoi(str));
            curr->left = l;
            q.push(l);
        }

        getline(s, str, ',');
        if (str == "#")
        {
            curr->right = NULL;
        }
        else
        {
            Node *r = new Node(stoi(str));
            curr->right = r;
            q.push(r);
        }
    }
    return root;
}

int main(int argc, char const *argv[])
{
    Node *root = new Node(10);
    root->left = new Node(20);
    root->right = new Node(30);
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    root->right->left = new Node(60);

    string serial = serialize(root);
    cout << serial;
    Node *root1 = deserialize(serial);
    printTree(root1);
    return 0;
}
