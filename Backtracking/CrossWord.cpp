#include <bits/stdc++.h>
using namespace std;
const int n = 10;

bool isvalidv(char cross[n][n], int r, int c, string word)
{
    int j = r;
    for (int i = 0; i < word.length(); i++)
    {
        if (j > 9)
            return false;
        if (cross[j][c] == '+' || (cross[j][c] != '-' && cross[j][c] != word[i]))
            return false;
        if (cross[j][c] == '-' || cross[j][c] == word[i])
            j++;
    }
    return true;
}

bool isvalidh(char cross[n][n], int r, int c, string word)
{
    int j = c;
    for (int i = 0; i < word.length(); i++)
    {
        if (j > 9)
            return false;
        if (cross[r][j] == '+' || (cross[r][j] != '-' && cross[r][j] != word[i]))
            return false;
        if (cross[r][j] == '-' || cross[r][j] == word[i])
            j++;
    }
    return true;
}

void set_v(char cross[n][n], int r, int c, vector<bool> &v, string word)
{
    int row = r;
    for (int i = 0; i < word.length(); i++)
    {
        if (cross[row + i][c] == '-')
        {
            cross[row + i][c] = word[i];
            v.push_back(true);
        }
        else
        {
            v.push_back(false);
        }
    }
}

void reset_v(char cross[n][n], int r, int c, vector<bool> v)
{
    int row = r;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i])
        {
            cross[row + i][c] = '-';
        }
    }
}

void set_h(char cross[n][n], int r, int c, vector<bool> &v, string word)
{
    int col = c;
    for (int i = 0; i < word.length(); i++)
    {
        if (cross[r][col + i] == '-')
        {
            cross[r][col + i] = word[i];
            v.push_back(true);
        }
        else
        {
            v.push_back(false);
        }
    }
}
void reset_h(char cross[n][n], int r, int c, vector<bool> v)
{
    int col = c;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i])
        {
            cross[r][col + i] = '-';
        }
    }
}

bool crossword(char cross[n][n], vector<string> words, int index)
{
    if (index >= words.size())
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << cross[i][j];
            }
            cout << endl;
        }
        cout << endl;
        return true;
    }
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            if (cross[r][c] == '-' || cross[r][c] == words[index][0])
            {
                if (isvalidv(cross, r, c, words[index]))
                {
                    vector<bool> helper;
                    set_v(cross, r, c, helper, words[index]);
                    if (crossword(cross, words, index + 1))
                    {
                        return true;
                    }
                    reset_v(cross, r, c, helper);
                }
                if (isvalidh(cross, r, c, words[index]))
                {
                    vector<bool> helper;
                    set_h(cross, r, c, helper, words[index]);
                    if (crossword(cross, words, index + 1))
                    {
                        return true;
                    }
                    reset_h(cross, r, c, helper);
                }
            }
        }
    }
    return false;
}

int main()
{
    char arr[n][n];
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = s[j];
        }
    }
    string s;
    cin >> s;
    vector<string> words;
    for (int i = 0; i < s.length(); i++)
    {
        int j = i;
        while (s[j] != ';' && j < s.length())
        {
            j++;
        }
        words.push_back(s.substr(i, j - i));
        i = j;
        j++;
    }
    crossword(arr, words, 0);
}