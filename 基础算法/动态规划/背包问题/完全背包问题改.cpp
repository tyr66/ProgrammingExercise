#include<iostream>

using namespace std;

int dp[201];
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
        for (int j = w[i]; j <= M;j++)
        {
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }
    
    printf("max=%d\n",dp[M]);

    return 0;
}