#include<iostream>

using namespace std;

int dp[101];

int main()
{
    int N;
    cin >> N;

    int prev = dp[0];
    int val;
    int res = 0;

    for (int k = 1; k <= N;k++)
    {
        for (int i = 1; i <= k;i++)
        {
            cin >> val;
            val = max(dp[i],prev)+val;
            prev = dp[i];
            dp[i] = val;
        }
    }

    for (int i = 1; i <= N;i++)
        res = max(res,dp[i]);

    cout << res << endl;
    return 0;
}