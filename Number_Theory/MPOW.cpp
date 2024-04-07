#include <bits/stdc++.h>
using namespace std;
#define int long long
int m, n;
const int MOD = 1e9 + 7;

void printMatrix(vector<vector<int>> &arr)
{
    for (auto &vec : arr)
    {
        for (auto &i : vec)
            cout << i << " ";
        cout << endl;
    }
}

void matMul(vector<vector<int>> &A, vector<vector<int>> &B, int m)
{
    vector<vector<int>> res(m, vector<int>(m));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < m; j++)
        {
            res[i][j] = 0;
            for (int k = 0; k < m; k++)
            {
                res[i][j] += (A[i][k] * B[k][j]) % MOD;
                res[i][j] %= MOD;
            }
        }
    }
    A = res;
}

void power(vector<vector<int>> &arr, vector<vector<int>> &I, int m, int n)
{
    for (int i = 0; i < m; i++)
        I[i][i] = 1;

    // for (int i = 0; i < n; i++)
    //     matMul(I, arr, m);

    while (n > 0)
    {
        if (n & 1)
            matMul(I, arr, m), --n;
        else
            matMul(arr, arr, m), n >>= 1;
    }
    arr = I;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        vector<vector<int>> arr = {{1, 1}, {1, 0}};
        vector<vector<int>> I = {{1, 0}, {0, 1}};
        power(arr, I, m, n);
        printMatrix(arr);
    }
    return 0;
}