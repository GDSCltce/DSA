#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;
signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, e;
        cin >> n >> e;
        vector<vector<int>> graph(n + 1, vector<int>(n + 1, inf));
        for (int i = 1; i <= n; i++)
        {
            graph[i][i] = 0;
        }

        for (int i = 0; i < e; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            graph[x][y] = graph[y][x] = min(graph[x][y], z);
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    if (graph[i][k] != inf && graph[k][j] != inf)
                        graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j]);
                }
            }
        }

        int q;
        cin >> q;
        while (q--)
        {
            int x, y;
            cin >> x >> y;
            cout << graph[x][y] << endl;
        }
    }
    return 0;
}