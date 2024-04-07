#include <bits/stdc++.h>
using namespace std;

int calculateMex(unordered_set<int> &st)
{
    int mex = 0;
    while (st.find(mex) != st.end())
        mex++;
    return mex;
}

int calculateGrundy(int n)
{
    if (n == 0)
        return 0;

    unordered_set<int> st;
    st.insert(calculateGrundy(n / 2));
    st.insert(calculateGrundy(n / 3));
    st.insert(calculateGrundy(n / 6));
    return calculateMex(st);
}

signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << calculateGrundy(n) << endl;
    }
    return 0;
}