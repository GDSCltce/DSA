#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int cnt;
    Node *child[26] = {NULL};
    Node() { cnt = 0; }
};
Node *root = nullptr;
void insert(string &a)
{
    Node *curr = root;
    for (int i = 0; i < a.length(); i++)
    {
        int val = (a[i] - 'a');
        if (curr->child[val] == NULL)
            curr->child[val] = new Node();
        curr = curr->child[val];
    }
    curr->cnt++;
}

string search(string &s)
{
    Node *curr = root;
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (curr->child[s[i] - 'a'] != NULL)
        {
            curr = curr->child[s[i] - 'a'];
            ans += s[i];
        }
        else
        {
            break;
        }
    }
    if (curr->cnt)
    {
        return ans;
    }
    for (int i = 0; i < 26; i++)
    {

        if (curr->child[i] != NULL)
        {
            curr = curr->child[i];

            char c = 'a';
            c += i;
            i = -1;
            ans += c;

            if (curr->cnt)
                return ans;

            continue;
        }
    }
    return ans;
}

signed main()
{
    int n;
    cin >> n;
    root = new Node();
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> s[i];
    }
    int q;
    cin >> q;
    vector<pair<string, int>> v[n + 1];
    for (int i = 1; i <= q; i++)
    {
        int r;
        string s;
        cin >> r >> s;
        v[r].push_back({s, i});
    }
    string ans[q + 1];
    for (int i = 1; i <= n; i++)
    {
        int sz = v[i].size();
        insert(s[i]);
        for (int j = 0; j < sz; j++)
        {
            string temp = search(v[i][j].first);
            ans[v[i][j].second] = temp;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}