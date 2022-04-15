#include<iostream>

using namespace std;

int mat[101][101];
int dp[101][101];

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N;i++)
    {
        for (int j = 1; j <= N;j++)
        {
            cin >> mat[i][j];
            mat[i][j] += mat[i][j-1];
            dp[i][j] = (-2147483647 - 1);
        }
    }

    int res = (-2147483647 - 1);
    for (int k = 0; k < N;k++)
    {
        for (int j = k+1; j <= N;j++)
        {
            int ans = 0;
            for (int i = 1; i <= N;i++)
            {
                if(ans>0)
                {
                    ans += (mat[i][j] - mat[i][k]);
                    dp[i][j] = max(dp[i][j],ans);
                }else
                {
                    ans = (mat[i][j] - mat[i][k]);
                    dp[i][j] = max((mat[i][j] - mat[i][k]),dp[i][j]);
                }

                res = max(res,dp[i][j]);
            }
        }
    }
    
    cout << res << endl;

    return 0;
}