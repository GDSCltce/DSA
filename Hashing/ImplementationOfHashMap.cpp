#include <bits/stdc++.h>
// #include "array.h"
using namespace std;

#define endl '\n'
#define ll long long int
#define space ' '
#define dbg(x) printf("%s = %d\n", #x, x);
// const int mod = 1000000007;
/*************************************/

class MyHashMap
{
	vector<list<pair<int, int>>> map;
	int CAP = 769;

public:
	MyHashMap()
	{
		map.resize(CAP);
	}

	void put(int key, int value)
	{
		auto &list = map[key % CAP];
		for (auto &x : list)
		{
			if (x.first == key)
			{
				x.second = value;
				return;
			}
		}
		list.emplace_back(key, value);
	}

	int get(int key)
	{
		auto &list = map[key % CAP];
		if (&list == NULL)
		{
			return -1;
		}
		for (auto &x : list)
		{
			if (x.first == key)
			{
				return x.second;
			}
		}
		return -1;
	}

	void remove(int key)
	{
		auto &pairs = map[key % CAP];
		for (auto i = pairs.begin(); i != pairs.end(); i++)
		{
			if (i->first == key)
			{
				pairs.erase(i);
				return;
			}
		}
	}

	void print()
	{int a = 0;
		for (auto i : map)
		{
			cout << a++ ;
			for (auto x : i)
			{
				cout << " --> {"<< x.first << ", " << x.second << "}";
			}
			cout << endl;	
		}
	}
};

inline void solve()
{
	MyHashMap has;

	has.put(1, 1);
	has.put(2, 2);
	has.get(1);
	has.put(2, 1);
	has.get(2);
	// has.remove(2);
	has.get(2);

	has.print();
}

int main()
{
#ifndef ONLINE_JUDGE
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
