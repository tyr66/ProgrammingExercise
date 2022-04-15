#include<iostream>

using namespace std;

int dp[1001];
int t[101];
int v[101];

int main()
{
    int T, N;
    cin >> T >> N;

    for (int i = 1; i <= N;i++)
    {
        cin >> t[i] >> v[i];
    }

    for (int i = 1; i <= N;i++)
    {
        for (int j = T; j >= t[i];j--)
        {
            dp[j] = max(dp[j],dp[j-t[i]]+v[i]);
        }
    }

    cout << dp[T]<<endl;

    return 0;
}