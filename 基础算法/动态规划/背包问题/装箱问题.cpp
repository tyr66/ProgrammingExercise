#include<iostream>

using namespace std;

int dp[20001];
int w[31];

int main()
{
    int W,N;
    cin >> W >> N;

    for (int i = 1; i <= N;i++)
    {
        cin >> w[i];
    }

    for (int i = 1; i <= N;i++)
    {
        for (int j = W; j >= w[i];j--)
        {
            dp[j] = max(dp[j],dp[j-w[i]]+w[i]);
        }
    }

    cout << W - dp[W]<<endl;

    return 0;
}