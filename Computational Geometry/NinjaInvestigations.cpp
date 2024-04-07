#include <bits/stdc++.h>
using namespace std;
#define INF 50000
#define MIN(x,y) (x < y ? x : y)
#define MAX(x,y) (x > y ? x : y)


struct Point
{
    double x, y;
    Point() {}
    Point(double a, double b) {
        x = a;
        y = b;
    }
    double cross(Point p)
    {	
        return x * p.y - y * p.x;
    }
    double distance(Point p)
    {	
        double dis =  sqrt((pow(p.x - x, 2.0) +  pow(p.y - y, 2.0)) * 1.0) ;
        return sqrt(pow(p.x - x, 2) +  pow(p.y - y, 2) * 1.0);
    }
};

double polygonArea(Point arr[], int n)
{   
    
    double a = arr[n - 1].cross(arr[0]);
    
    for (int i = 0; i < int(n) - 1; i++)
    {
        a += arr[i].cross(arr[i + 1]);
    }
    return a/2;
}

int probability_(Point arr[], int n, Point p, Point app)
{   
    int area = polygonArea(arr, n);
    int dis = app.distance(p);
    int prob = (dis*1.0 / area*1.0) * 100;
    return 100 - prob;
}

int isInside(Point polygon [],int N,Point p)
{
    int counter = 0;
    int i;
    double xinters;
    Point p1,p2;

    p1 = polygon[0];
    for (i = 1; i <= N; i++)
    {
        p2 = polygon[i % N];
        if (p.y > MIN(p1.y,p2.y)) {
            if (p.y <= MAX(p1.y,p2.y)) {
                if (p.x <= MAX(p1.x,p2.x)) {
                    if (p1.y != p2.y) {
                        xinters = (p.y-p1.y)*(p2.x-p1.x)/(p2.y-p1.y)+p1.x;
                        if (p1.x == p2.x || p.x <= xinters)
                            counter++;
                    }
                }
            }
        }

    p1 = p2;
    }

    if (counter % 2 == 0)
        return 1;
    else
        return 0;
}


int main()
{
    int t;   // Test Cases
    cin >> t;
    while (t--)
    {
        int n;   // Number of vertices in vicintiy of the bomb
        cin >> n;
        Point arr[n];
        for (int i = 0; i < n; i++)
        {
            double a, b;
            cin >> a >> b;
            arr[i] = Point(a, b);    // Coordinated of vertices in vicintiy of the bomb
        }
        
        double a, b;
        cin >> a >> b;
        Point approx(a, b);        // Approx coordinates of the bomb

        int q;
        cin >> q;                 // Number of coordinates to be checked

        for (int i = 0; i < q; i++)
        {
            int a, b;
            cin >> a >> b;
            Point ch(a, b);
            if(!isInside(arr, n, ch)) {
                cout << "Yes" << endl;
                cout << probability_(arr, n, ch, approx) << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
    }
}