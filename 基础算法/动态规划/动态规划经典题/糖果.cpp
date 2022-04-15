#include<iostream>

using namespace std;

int dp[101][100];
int arr[101];

int main()
{
    int N, K;
    cin >> N >> K;

    for (int i = 1; i <= N;i++)
        cin >> arr[i];

    for (int i = 1; i <= N;i++)
    {
        for (int j = 0; j < K;j++)
        {
            dp[i][j] = dp[i-1][j];
            //第三层循环可以简化为一条语句但为了方便理解保留：
            //dp[i][j] = max(dp[i-1][j],dp[i-1][(j-a[i]%K+K)%K]+arr[i]);
            for (int k = 0; k < K;k++)
                if((arr[i]+dp[i-1][k])%K == j)
                    dp[i][j] = max(dp[i][j],arr[i]+dp[i-1][k]);                
        }
    }

    cout << dp[N][0]<<endl;

    return 0;
}