#include<iostream>
#include<algorithm>
using namespace std;

struct Interval
{
    int st;
    int ed;
};

Interval intervals[1000];

bool cmp(const Interval&a,const Interval&b)
{
    return a.ed < b.ed;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0;i < n;i++)
        cin >> intervals[i].st >> intervals[i].ed;

    sort(intervals,intervals+n,cmp);

    int count = 0;
    int tar = 0;
    int i;

    while (tar < n)
    {
        for (i = tar + 1; i < n; i++)
        {
            if (intervals[tar].ed < intervals[i].st)
            {
                break;
            }
        }

        count++;
        tar = i;
    }

    cout << count << endl;

    return 0;
}