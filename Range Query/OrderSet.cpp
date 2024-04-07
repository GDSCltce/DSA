#include <bits/stdc++.h>
using namespace std;
#define maxN 200001
struct query
{
    int x;
    char c;
} arr[maxN];

map<int, int> mp;
int mp2[maxN], ft[maxN];
bool use[maxN];

int query(int index)
{
    int sum = 0;
    for (; index > 0; index -= (index & -index))
        sum += ft[index];
    return sum;
}
void update(int index, int val)
{
    for (; index < maxN; index += (index & -index))
        ft[index] += val;
}
int main()
{
    int n, timer = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].c >> arr[i].x;
        if (arr[i].c == 'I' || arr[i].c == 'D' || arr[i].c == 'C')
            mp[arr[i].x]= i;
    }
    for (auto &i : mp)
    {
        i.second = ++timer;
        mp2[timer] = i.first;
    }
    for (int i = 1; i <=n; i++)
    {
        if (arr[i].c == 'I' || arr[i].c == 'D' || arr[i].c == 'C')
            arr[i].x = mp[arr[i].x];
    }
    for (int i = 1; i <= n; i++)
    {
        if(arr[i].c == 'I')
        {
            if(!use[arr[i].x])
            {
                update(arr[i].x, 1);
                use[arr[i].x] = true;
            }
        }
        else if (arr[i].c == 'D')
        {
            if (use[arr[i].c])
            {
                update(arr[i].x, -1);
                use[arr[i].x] = false;
            }
        }
        else if (arr[i].c == 'K')
        {
            int start=1, end = n, k = arr[i].x;
            bool flag = true;
            while (start <= end)
            {
                int mid = (start + end)/2, curr = query(mid), prev = query(mid-1);
                if (curr == k && (mid == 1|| prev == k-1))
                {
                    flag = false;
                    cout << mp2[mid];break;
                }
                else if (curr < k)  
                {
                    start = mid + 1;
                }
                else
                {
                    end = mid -1;
                }
            }
            if (flag)cout << "invalid";
        }
        else
        {
            cout << query(arr[i].x-1);
        }
        cout << endl;
    }
    
    
    return 0;
}
