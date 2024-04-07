#include <bits/stdc++.h>
using namespace std;

class Trie
{
    struct Node
    {
        Node *one, *zero;
        int cnt[2];
        Node()
        {
            one = zero = NULL;
            cnt[0] = cnt[1] = 0;
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
    Node *__delete(Node *curr, int x, int i)
    {
        if (!curr || i < 0)
            return NULL;
        int b = (x >> i) & 1;
        if (b == 0)
            curr->zero = __delete(curr->zero, x, i - 1);

        else
            curr->one = __delete(curr->one, x, i - 1);
        if (!curr->zero && !curr->one)
        {
            delete curr;
            return NULL;
        }
        return curr;
    }
    void _delete(int n)
    {
        Node *curr = root;
        root = __delete(curr, n, 31);
    }
    int findMaxXorPair(const int val)
    {
        Node *curr = root;
        int currxor = 0;
        for (int j = 31; curr && j >= 0; j--)
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
        return currxor;
    }
};

signed main()
{
    int q;
    cin >> q;
    Trie *root = new Trie();
    root->insert(0);
    unordered_map<int, int> mp;
    for (int i = 0; i < q; i++)
    {
        char x;
        int val;
        cin >> x >> val;
        if (x == '?')
        {
            cout << root->findMaxXorPair(val) << endl;
        }
        else if (x == '+')
        {
            root->insert(val), mp[val]++;
        }
        else if (x == '-')
        {
            if (mp[val] == 1)
                root->_delete(val), mp[val]--;
            else
                mp[val]--;
        }
    }

    return 0;
}