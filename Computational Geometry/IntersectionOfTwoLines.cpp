#include <bits/stdc++.h>
using namespace std;
struct Point
{
    int x, y;
};

// check if q lies on segment pr
bool onSegment(Point p, Point q, Point r)
{
    return (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
            q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y));
}

int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0)
        return 0;             // p, q, r are collinear
    return (val > 0) ? 1 : 2; // 1 -> Clockwise , 2 -> CounterClockwise
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    // General Case
    if (o1 != o2 && o3 != o4)
        return true;

    // Special Case
    if (o1 == 0 && onSegment(p1, p2, q1)) // p1, p2, q1 are collinear
        return true;                      // and p2 lies on segment p1,q1
    if (o2 == 0 && onSegment(p1, q2, q1)) // p1, q2, q1 are collinear
        return true;                      // and q2 lies on segment p1,q1
    if (o3 == 0 && onSegment(p2, p1, q2)) // p2, p1, q2 are collinear
        return true;                      // and p1 lies on segment p2,q2
    if (o4 == 0 && onSegment(p2, q1, q2)) // p2, q1, q2 are collinear
        return true;                      // and q1 lies on segment p2,q2

    return false;
}

signed main()
{
    Point p1 = {1, 1}, q1 = {10, 1};
    Point p2 = {1, 2}, q2 = {10, 2};
    if (doIntersect(p1, q1, p2, q2))
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }
    return 0;
}