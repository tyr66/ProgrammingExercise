#include<iostream>

using namespace std;

int dp[201];
int w[31];
int v[31];
int nums[31];

int main()
{
    int M, N;
    cin >> M >> N;

    for (int i = 1; i <= N;i++)
    {
        cin >> w[i] >> v[i]>>nums[i];
    }

    for (int i = 1; i <= N; i++)
    {
        if(nums[i] == 0)
        {
            //完全背包
            for (int j = w[i]; j <= M;j++)
            {
                dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
            }
        }else
        {
            //01或者是多重背包
            for (int j = M; j > w[i];j--)
            {
                for (int k = 0; k <= nums[i];k++)
                {
                    if(j-w[i]*k<0)
                    break;
                    dp[j] = max(dp[j],dp[j-w[i]*k]+v[i]*k);
                }
            }
        }
    }

    cout << dp[M]<<endl;

    return 0;
}