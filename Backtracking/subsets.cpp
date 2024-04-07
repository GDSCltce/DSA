#include <bits/stdc++.h>
using namespace std;

void printSubsets(string s, int index, string ans = "")
{
    if (index >= s.size())
    {
        cout << ans << endl;
        return;
    }
    printSubsets(s, index + 1, ans);
    printSubsets(s, index + 1, ans + s[index]);
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    printSubsets(s, 0);
    return 0;
}

/*
Power set : [ 1, 2, 3 ] = [], [1], [2], [3], [ 1, 2 ], [ 1, 3 ], [ 2, 3 ], [ 1, 2, 3 ]
 */