#include <bits/stdc++.h>
using namespace std;
#define int long long
class Trie
{
    struct Node
    {
        bool end;
        Node *child[2];
        Node()
        {
            end = false;
            child[0] = child[1] = NULL;
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
            if (!curr->child[b])
                curr->child[b] = new Node();
            curr = curr->child[b];
        }
        curr->end = true;
    }
    int query(int val)
    {
        Node *curr = root;
        int ans = 0;
        for (int i = 31; i >= 0; i--)
        {
            int b = (val >> i) & 1;
            if (curr->child[1 - b])
            {
                ans |= (1LL << i);
                curr = curr->child[1 - b];
            }
            else if (curr->child[b])
                curr = curr->child[b];
            else
                break;
        }
        return ans;
    }
};

signed main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    Trie *root = new Trie();
    root->insert(arr[0]);
    int currxorr = arr[0];
    int maxxorr = arr[0];
    for (int i = 1; i < n; i++)
    {
        currxorr ^= arr[i];
        int ans = root->query(currxorr);
        maxxorr = max({maxxorr, currxorr, ans});
        root->insert(currxorr);
    }
    cout << maxxorr;

    return 0;
}