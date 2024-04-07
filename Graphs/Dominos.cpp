#include <bits/stdc++.h>
using namespace std;
void dfs(vector<int> graph[], bool visited[], int vertex, stack<int> &st, bool flag)
{
    visited[vertex] = true;
    for (auto &i : graph[vertex])
    {
        if (!visited[i])
            dfs(graph, visited, i, st, flag);
    }
    if (flag)
        st.push(vertex);
    
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        bool vis[n + 1];
        memset(vis, false, sizeof vis);
        stack<int> st;
        vector<int> graph[n + 1];
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            graph[a].push_back(b);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                dfs(graph, vis, i, st, true);
            }
        }
        memset(vis, false, sizeof(vis));
        int count = 0;
        while (!st.empty())
        {
            int vertex = st.top();
            st.pop();
            if (!vis[vertex])
            {
                dfs(graph, vis, vertex, st, false);
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}