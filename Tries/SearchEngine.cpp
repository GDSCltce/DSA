#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node **children;
    int weight;

    Node()
    {
        children = new Node *[26];
        for (int i = 0; i < 26; i++)
            children[i] = NULL;
        weight = 0;
    }
};

void insert(string s, int weight, Node *root)
{
    if (s.empty())
        return;
    Node *child = nullptr;
    int idx = s[0] - 'a';
    if (root->children[idx])
        child = root->children[idx];
    else
    {
        child = new Node();
        root->children[idx] = child;
    }
    if (child->weight < weight)
        child->weight = weight;
    insert(s.substr(1), weight, child);
}
int search(string &s, Node *root)
{
    int bestWeight = -1;
    Node *curr = root;
    for (int i = 0; i < s.size(); i++)
    {
        int idx = s[i] - 'a';
        Node *child = curr->children[idx];
        if (child)
        {
            curr = child;
            bestWeight = child->weight;
        }
        else
        {
            return -1;
        }
    }
    return bestWeight;
}
vector<int> searchEngine(vector<pair<string, int>> database, vector<string> text)
{
    Node *root = new Node();
    for (auto i : database)
    {
        insert(i.first, i.second, root);
    }
    vector<int> ans;
    for (auto i : text)
    {
        ans.push_back(search(i, root));
    }
    return ans;
}

signed main()
{
    int n, q;
    cin >> n >> q;
    Node *root = new Node();
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int weight;
        cin >> weight;
        insert(s, weight, root);
    }

    // queries
    while (q--)
    {
        string t;
        cin >> t;
        cout << search(t, root) << endl;
    }
    return 0;
}