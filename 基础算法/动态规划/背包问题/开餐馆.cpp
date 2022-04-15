#include<iostream>

using namespace std;

/**
 * 思路
 * 跟背包一点关系都没有
 */

int dp[101];
int pos[101];
int profit[101];

int main()
{
    int t,N,K;
    cin >> t;

    while(t>0)
    {
        cin >> N >> K;

        int res = 0;

        for (int i = 1; i <= N;i++)
            cin>>pos[i];

        for (int i = 1; i <= N;i++)
            cin >> profit[i];

        memset(dp,0,sizeof(dp));

        for (int i = 1; i <= N;i++)
        {
            dp[i] = profit[i];

            for (int j = 1; j < i;j++)
            {
                if(pos[i]-pos[j]>K)
                {
                    dp[i] = max(dp[i],dp[j]+profit[i]);
                }
            }

            res = max(res,dp[i]);
        }

        cout << res << endl;

        t--;
    }

    return 0;
}