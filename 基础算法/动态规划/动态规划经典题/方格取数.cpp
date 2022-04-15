#include<iostream>

using namespace std;

/**
 * 思路：多维动态规划，我们让两个人同时从原点出发，只要不让两个人同时去拿一个位置上的分数就行。
 * dp数组的形式为：dp[i][j][l][k]，表示两个人分别站在(i,j)和(l,k)的位置上时能取得的最大分数和
 *                  
 *                  max(dp[i-1][j][l-1][k],dp[i-1][j][l][k-1],dp[i][j-1][l-1][k],dp[i][j-1][l][k-1])+map[i][j]+map[l][k] ,当(i,j)!=(l,k)时
 *  dp[i][j][l][k]= max(dp[i-1][j][l-1][k],dp[i-1][j][l][k-1],dp[i][j-1][l-1][k],dp[i][j-1][l][k-1])+map[i][j]           ,当(i,j)==(l,k) 时 
 */

int dp[11][11][11][11];
int map[11][11];

void input()
{
    int i, j,k;

    while(cin>>i>>j>>k)
    {
        if (i == 0&&j==0&&k==0)
            break;

        map[i][j] = k;
    }
}

int max4(int a,int b,int c,int d)
{
    return max(max(a,b),max(c,d));
}

int main()
{
    int n;
    cin >> n;

    input();

    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            for (int l = 1; l <= n;l++)
            {
                for (int k = 1; k <= n;k++)
                {
                    dp[i][j][l][k] = max4(dp[i-1][j][l-1][k],dp[i-1][j][l][k-1],dp[i][j-1][l-1][k],dp[i][j-1][l][k-1]);

                    if(i==l&&j==k)
                    {
                        dp[i][j][l][k] += map[i][j];
                    }else{

                        dp[i][j][l][k] += map[i][j]+map[l][k];
                    }
                }
            }
        }
    }

    cout << dp[n][n][n][n]<<endl;

    return 0;
}