#include <bits/stdc++.h>
using namespace std;
#define int long long

int areaOfConvexPolygon(vector<int> &x, vector<int> &y)
{
	int n = x.size();
	double area = 0;
	for (int i = 1; i < n - 1; i++)
	{
		double x1 = x[i] - x[0];
		double y1 = y[i] - y[0];
		double x2 = x[i + 1] - x[0];
		double y2 = y[i + 1] - y[0];

		area += (x1 * y2) - (y1 * x2);
	}

	return (int)abs(area) / 2;
}

signed main()
{
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> x(n), y(n);
		for (int i = 0; i < n; i++)
			cin >> x[i] >> y[i];

		cout << areaOfConvexPolygon(x,y);
		cout << endl;
	}
	return 0;
}

/* 
1
4
1 5
2 2
9 2
7 5 
*/