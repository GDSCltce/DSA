#include <bits/stdc++.h>
using namespace std;

string getPossChars(int c)
{
    switch (c)
    {
    case 0:
        return "";
    case 1:
        return "";
    case 2:
        return "abc";
    case 3:
        return "def";
    case 4:
        return "ghi";
    case 5:
        return "jkl";
    case 6:
        return "mno";
    case 7:
        return "pqrs";
    case 8:
        return "tuv";
    case 9:
        return "wxyz";
    default:
        return "";
    }
    return "";
}

void keypad(string s, int index, vector<string> &ans, string s_ans = "")
{
    // base - case
    if (s.size() <= index)
    {
        ans.push_back(s_ans);
        return;
    }
    int num = s[index] - '0';
    string numString = getPossChars(num);
    for (int i = 0; i < numString.size(); i++)
    {
        keypad(s, index + 1, ans, s_ans + numString[i]);
    }
    return;
}

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;
    vector<string> ans;

    keypad(s, 0, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}