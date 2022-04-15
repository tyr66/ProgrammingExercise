#include<iostream>
#include<algorithm>
using namespace std;

//思路：动态规划
//解法和求最长不下降序列差不多，需要注意如何判断桥梁之间是否和交叉。例如1,3和2,4 是不会交叉的，这和区间是不一样的。

struct Interval
{
    int i, j;
};

int dp[5000];
Interval intervals[5000];

bool cmp(const Interval&a,const Interval&b)
{
    return a.i < b.i;
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n;i++)
    {
        cin >> intervals[i].i >> intervals[i].j;
    }

    sort(intervals,intervals+n,cmp);

    int res = (-2147483647 - 1);
    dp[0] = 1;

    for (int i = 1; i < n;i++)
    {
        int maxIdx = i;
        for (int j = i - 1; j >= 0;j--)
        {
            if(intervals[i].j>intervals[j].j&&dp[maxIdx]<dp[j])
            {
                maxIdx = j;
            }
        }

        dp[i] = dp[maxIdx]+1;
        res = max(res,dp[i]);
    }

    cout << res << endl;

    return 0;
}