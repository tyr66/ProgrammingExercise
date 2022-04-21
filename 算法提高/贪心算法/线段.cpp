#include<iostream>
#include<algorithm>
using namespace std;

struct Interval
{
    int s;
    int f;
};

bool cmp(const Interval&a,const Interval&b)
{
    return a.f < b.f;
}

Interval intervals[1000001];

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N;i++)
    {
        cin >> intervals[i].s >> intervals[i].f;
    }

    sort(intervals,intervals+N,cmp);

    int f = 0;
    int res = 0;
    for (int i = 0; i < N;i++)
    {
        if(f<=intervals[i].s)
        {
            res++;
            f = intervals[i].f;
        }
    }

    cout << res << endl;
    return 0;
}