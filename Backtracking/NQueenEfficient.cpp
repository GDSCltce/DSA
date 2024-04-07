#include <bits/stdc++.h>
using namespace std;

#define debug(x)                    \
    cout << #x << " = ", _print(x); \
    cout << endl;
/*-------------------ASIMARIES--------------------*/

void _print(string t) { cout << t; }
void _print(char t) { cout << t; }
template <class T>
void _print(vector<T> v);
template <class T>
void _print(vector<T> v)
{
    cout << "[ ";
    for (T i : v)
        _print(i), cout << " ";
    cout << "]";
}
void solve(int col, vector<string> &board, vector<vector<string>> &ans,
           vector<int> &leftRow,
           vector<int> &upperDiagonal, vector<int> &lowerDiagonal, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (leftRow[i] == 0 && lowerDiagonal[i + col] == 0 &&
            upperDiagonal[n - 1 + col - i] == 0)
        {
            board[i][col] = 'Q';
            leftRow[i] = 1;
            lowerDiagonal[i + col] = 1;
            upperDiagonal[n - 1 + col - i] = 1;
            solve(col + 1, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
            board[i][col] = '.';
            leftRow[i] = 0;
            lowerDiagonal[i + col] = 0;
            upperDiagonal[n - 1 + col - i] = 0;
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }
    vector<int> leftRow(n, 0), upperDiagonal(2 * n - 1, 0), lowerDiagonal(2 * n - 1, 0);
    solve(0, board, ans, leftRow, upperDiagonal, lowerDiagonal, n);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> ans = solveNQueens(n);
    debug(ans);
    return 0;
}