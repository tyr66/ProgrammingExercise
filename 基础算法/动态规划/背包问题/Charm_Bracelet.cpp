#include<iostream>

using namespace std;

int dp[12881];
int w[3501];
int v[3501];

int main()
{
    int N,W;
    cin >> N >> W;

    for (int i = 1; i <= N;i++)
        cin >> w[i]>>v[i];

    for (int i = 1; i <= N;i++)
    {
        for (int j = W; j >= w[i];j--)
        {
            dp[j] = max(dp[j],dp[j-w[i]]+v[i]);
        }
    }

    cout << dp[W]<<endl;

    return 0;
}