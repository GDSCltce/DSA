#include <bits/stdc++.h>
using namespace std;

struct edge
{
    int ei, ej, cost;
};

int find_parent(int num, int *parents, int *rank)
{
    if (num == parents[num])
    {
        return num;
    }
    int p = find_parent(parents[num], parents, rank);
    if (rank[p] <= rank[num])
    {
        parents[p] = num;
        rank[num]++;
    }
    else
    {
        parents[num] = p;
        rank[p]++;
    }
    return p;
}

bool compare(edge e1, edge e2)
{
    return e1.cost < e2.cost;
}

int main()
{
    int t;
    cin >> t;
    for (int iter = 1; iter <= t; iter++)
    {
        int n, m, a;
        cin >> n >> m >> a;
        edge *edges = new edge[m + 1];
        for (int i = 0; i < m; i++)
        {
            cin >> edges[i].ei >> edges[i].ej >> edges[i].cost;
        }
        sort(edges, edges + m, compare);
        int *parents = new int[n + 1];
        for (int i = 0; i <= n; i++)
        {
            parents[i] = i;
        }
        int *rank = new int[n + 1]{};
        int cost = 0;
        int j = 0;
        for (int i = 0; i < m && j < n - 1; i++)
        {
            edge e = edges[i];
            if (e.cost >= a)
            {
                break;
            }
            int p1 = find_parent(e.ei, parents, rank);
            int p2 = find_parent(e.ej, parents, rank);
            if (p1 != p2)
            {
                cost += e.cost;
                if (rank[p1] <= rank[p2])
                {
                    parents[p1] = p2;
                    rank[p2]++;
                }
                else
                {
                    parents[p2] = p1;
                    rank[p1]++;
                }
                j++;
            }
        }
        int numair = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i == parents[i])
            {
                cost += a;
                numair += 1;
            }
        }
        cout << cost << "\n";
    }
    return 0;
}