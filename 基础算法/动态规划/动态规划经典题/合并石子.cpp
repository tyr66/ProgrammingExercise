#include<iostream>
#include<cstring>
using namespace std;

/**
 * 思路
 * 状态转移方程为：dp[i][j]=min(dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1],dp[i][j])
 */

int dp[101][101];
int arr[101];
int sum[101][101];

int main()
{
    int N;
    cin >> N;

    memset(dp,0x3f3f3f3f,sizeof(dp));

    for (int i = 1; i <= N;i++)
    {
        cin >> arr[i];
        dp[i][i] = 0;
    }


    for (int i = 1; i <= N;i++)
    {
        for (int j = i; j <= N;j++)
        {
            sum[i][j] = sum[i][j-1]+arr[j];
        }
    }

    for (int i = N; i > 0;i--)
    {
        for (int j = i + 1; j <= N;j++)
        {
            for (int k = i; k < j;k++)
            {
                dp[i][j] = min(dp[i][k]+dp[k+1][j]+sum[i][j],dp[i][j]);
            }
        }
    }

    cout << dp[1][N]<<endl;
    return 0;
}