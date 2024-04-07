#include <bits/stdc++.h>
using namespace std;
#define int long long
class Trie
{
    struct Node
    {
        bool end;
        Node *child[2];
        int cnt[2];
        Node()
        {
            end = false;
            child[0] = child[1] = NULL;
            cnt[0] = cnt[1] = 0;
        }
    };
    Node *root;

public:
    Trie() { root = new Node(); }
    void insert(int val)
    {
        Node *curr = root;
        for (int i = 31; i >= 0; i--)
        {
            int b = (val >> i) & 1;
            curr->cnt[b]++;
            if (!curr->child[b])
                curr->child[b] = new Node();
            curr = curr->child[b];
        }
        curr->end = true;
    }
    int findCNTSubarray(int k, int val)
    {
        Node *curr = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int bk = (k >> i) & 1;
            int bval = (val >> i) & 1;
            if (bk)
            {
                ans += curr->cnt[bval];
                if (!curr->child[1LL - bval])
                    return ans;
                curr = curr->child[1LL - bval];
            }
            else
            {
                if (!curr->child[bval])
                    return ans;
                curr = curr->child[bval];
            }
        }
        return ans;
    }
};

signed main()
{
    int n, k;
    cin >> n >> k;
    int temp1, temp2, temp3 = 0;
    Trie *root = new Trie();
    root->insert(0);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> temp1;
        temp2 = temp3 ^ temp1;
        ans += root->findCNTSubarray(k, temp2);
        root->insert(temp2);
        temp3 = temp2;
    }
    cout << ans;

    return 0;
}