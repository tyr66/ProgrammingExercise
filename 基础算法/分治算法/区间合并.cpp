#include <iostream>
#include <algorithm>
using namespace std;

struct Interval
{
    int s;
    int f;
};

Interval intervals[50001];

bool cmp(const Interval &a, const Interval &b)
{
    return a.s < b.s;
}

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        cin >> intervals[i].s >> intervals[i].f;
    }

    sort(intervals, intervals + N, cmp);

    bool flag = false;
    int s = intervals[0].s;
    int f = intervals[0].f;
    for (int i = 1; i < N; i++)
    {
        if (intervals[i].s >= s && intervals[i].s <= f)
        {
            flag = true;
            f = max(f, intervals[i].f);
        }
        else
        {
            flag = false;
            break;
        }
    }

    if (flag)
        cout << s << " " << f << endl;
    else
        cout << "no\n";

    return 0;
}
