#include<iostream>

using namespace std;

int dp[101][101];
int map[101][101];

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N;i++)
    {
        for (int j = 1; j <= N;j++)
        {
            cin >> map[i][j];
        }
    }

    for (int i = 0; i <= N;i++)
    {
        dp[i][0] = 2147483647;
        dp[0][i] = 2147483647;
    }

    dp[0][1] = 0;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + map[i][j];
        }
    }

    cout << dp[N][N]<<endl;

    return 0;
}