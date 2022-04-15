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
            if(w[i]<=j)
            {
                dp[i][j] = max(dp[i-1][j-w[i]]+v[i],dp[i-1][j]);
            }else
            {
                dp[i][j] = dp[i-1][j];
            }
        }
    }

    cout << dp[N][M]<<endl;

    return 0;
}

