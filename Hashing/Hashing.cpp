#include <bits/stdc++.h>
#include "array.h"
using namespace std;

#define endl '\n'
#define ll long long int
#define space ' '
#define dbg(x) printf("%s = %d\n", #x, x);
// const int mod = 1000000007;
/*************************************/

class Hash
{
	int BUCKET;
	list<int> *table;

public:
	Hash(int b)
	{
		BUCKET = b;
		table = new list<int>[b];
	}
	void insert(int key)
	{
		int i = key % BUCKET;
		table[i].push_back(key);
	}
	void remove(int key)
	{
		int i = key % BUCKET;
		list<int>::iterator x;
		for (x = table[i].begin(); x != table[i].end(); i++)
		{
			if (*x == key)
				break;
			// table[i].remove(x);
		}
		if (x != table[i].end())
		{
			table[i].erase(x);
		}
	}
	bool search(int key)
	{
		int i = key % BUCKET;
		for (auto x : table[i])
			if (x == key)
				return true;
		return false;
	}

	void print()
	{
		for (int i = 0; i < BUCKET; i++)
		{
			cout << i;
			for (auto x : table[i])
			{
				cout << " --> " << x;
			}
			cout << endl;
		}
	}
};

inline void solve()
{
	int n, m, x;
	cin >> n >> m;
	Hash h(m);
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		h.insert(x);
	}
	// h.remove(95);
	// cout << h.search(72);
	// cout << h.search(49) << endl;
	h.print();
}

int main()
{
#ifndef asimaries
	freopen("in.in", "r", stdin);
	freopen("out.in", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	// int t;
	// scanf("%d", &t);
	// while (t--)
	{
		solve();
	}
	return 0;
}
