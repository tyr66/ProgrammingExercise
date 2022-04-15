#include<iostream>

using namespace std;

int dp[31][201];
int w[31];
int v[31];

int main()
{
    int M, N;
    cin >> M >> N;

    for (int i = 1; i <= N;i++)
    {
        cin >> w[i]>>v[i];
    }

    for (int i = 1; i <= N;i++)
    {
        for (int j = 1; j <= M;j++)
        {
            for (int k = 0; w[i] * k <= j;k++)
            {
                dp[i][j] = max(dp[i][j],dp[i-1][j-w[i]*k]+v[i]*k);
            }
        }
    }

    printf("max=%d\n",dp[N][M]);

    return 0;
}