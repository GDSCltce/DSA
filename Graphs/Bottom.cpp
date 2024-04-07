#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
bool vis[N];
stack<int> stk;

void dfs1(vector<int> graph[], int vertex)
{
    vis[vertex] = true;
    for (auto &i : graph[vertex])
    {
        if (!vis[i])
            dfs1(graph, i);
    }
    stk.push(vertex);
}
void dfs2(vector<int> graph[], int vertex, vector<int> &temp)
{
    vis[vertex] = true;
    temp.emplace_back(vertex);
    for (auto &i : graph[vertex])
    {
        if (!vis[i])
            dfs2(graph, i, temp);
    }
}

void getSCC(vector<int> graph[], vector<int> graphT[], vector<vector<int>> &ans, int n)
{
    memset(vis, 0, sizeof vis);
    stk = stack<int>();
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
            dfs1(graph, i);
    }

    memset(vis, 0, sizeof vis);
    while (!stk.empty())
    {
        int curr = stk.top();
        stk.pop();
        if (!vis[curr])
        {
            vector<int> temp;
            dfs2(graphT, curr, temp);
            ans.emplace_back(temp);
        }
    }
    return;
}

signed main()
{
    // freopen("in.in", "r", stdin);
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> graph[n];
        vector<int> graphT[n];
        for (int i = 0; i < m; i++)
        {
            int x, y;
            cin >> x >> y;
            graph[x - 1].emplace_back(y - 1);
            graphT[y - 1].emplace_back(x - 1);
        }
        vector<vector<int>> ans;

        getSCC(graph, graphT, ans, n);
        set<int> bottom;
        for (auto &vec : ans)
        {
            unordered_set<int> currc;
            for (auto &i : vec)
            {
                currc.insert(i);
            }
            bool flag = true;
            for (auto &i : currc)
            {
                for (auto &child : graph[i])
                {
                    if (!currc.count(child))
                    {
                        flag = false;
                        break;
                    }
                }
                if (!flag)
                    break;
            }
            if (flag)
            {
                for (auto &i : currc)
                {
                    bottom.insert(i);
                }
            }
        }
        for (auto &i : bottom)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}