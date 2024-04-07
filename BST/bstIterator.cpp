#include "BST.h"
class BSTIterator
{
    stack<Node *> stk;
    void pushALL(Node *root)
    {
        while (root)
        {
            stk.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(Node *root)
    {
        pushALL(root);
    }

    int next()
    {
        Node *tmpNode = stk.top();
        stk.pop();
        pushALL(tmpNode->right);
        return tmpNode->val;
    }

    bool hasNext()
    {
        return !stk.empty();
    }
};
