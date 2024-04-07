#include <bits/stdc++.h>
using namespace std;

class Trie
{
    struct Node
    {
        Node *one, *zero;
        Node()
        {
            one = zero = NULL;
        }
    };
    Node *root;

public:
    Trie()
    {
        root = new Node();
    }
    void insert(int n)
    {
        Node *curr = root;
        for (int i = 31; i >= 0; i--)
        {
            int b = (n >> i) & 1;
            if (b)
            {
                if (!curr->one)
                    curr->one = new Node();
                curr = curr->one;
            }
            else
            {
                if (!curr->zero)
                    curr->zero = new Node();
                curr = curr->zero;
            }
        }
    }
    int findMaxXorPair(vector<int> &arr)
    {
        int maxxor = -1e9 - 1e7, n = arr.size();
        for (int i = 0; i < n; i++)
        {
            int val = arr[i];
            Node *curr = root;
            int currxor = 0;
            for (int j = 31; j >= 0; j--)
            {
                int b = (val >> j) & 1;
                if (b)
                {
                    if (curr->zero)
                    {
                        currxor |= (1 << j);
                        curr = curr->zero;
                    }
                    else
                        curr = curr->one;
                }
                else
                {
                    if (curr->one)
                    {
                        currxor |= (1 << j);
                        curr = curr->one;
                    }
                    else
                        curr = curr->zero;
                }
            }
            maxxor = max(maxxor, currxor);
        }
        return maxxor;
    }
};

signed main()
{
    Trie *root = new Trie();
    vector<int> arr = {8, 1, 2, 15, 10, 5, 3};
    for (int i = 0; i < arr.size(); i++)
    {
        root->insert(arr[i]);
    }
    cout << root->findMaxXorPair(arr);
    return 0;
}