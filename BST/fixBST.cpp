#include "BST.h"

    
 
int main(int argc, char const *argv[])
{
    Node *root = NULL;
    int x;
    for (int i = 0; i < 10; i++)
    {
        cin >> x;
        root = insert(root, x);
    }
    printTree(root);
    return 0;
}