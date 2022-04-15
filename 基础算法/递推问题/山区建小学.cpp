#include<iostream>
#include<vector>
#include<cstdio>  
#include<algorithm>  
#include<cmath>  

using namespace std;

int dp[501][501];//dp[i][j]表示，在村庄1到村庄i之间建立j个校园的最小上学路径
int minDist[501][501];//minDist[i][j]表示在i,j 两个村庄中建立一个校园的最小上学路途
int s[501];//s[i] 表示从村庄1到村庄i的路径

//区间dp dp方程为 dp[i][j] = min(dp[i][j],dp[k][j-1]+minDist[k+1][j])
//一个结论：如果要在i..j中选一个点使所有点到这个点的总距离最小，这个点一定在中点位置。训练指南上有证明，
//其实很简单，反证法，假设不是中间的点，左移或右移一个点，会发现造价升高。
int calMindist(int i,int j)
{
    int mid = (i + j) >> 1;

    for (int k = i; k <= j;k++)
    {
        minDist[i][j] += abs(s[mid]-s[k]);
    }

    return minDist[i][j];
}

int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 2; i <= n;i++)
    {
        int tmp;
        cin >> tmp;
        s[i] = s[i-1]+tmp;
    }

    for (int i = 1; i <= n;i++)
        minDist[i][i] = 0;

    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            if(i==j)
                continue;

            minDist[i][j] = calMindist(i,j);
        }
    }

    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            //设置成INT_MAX
            dp[i][j] = 2147483647;
        }
    }

    for (int i = 1; i <= n;i++)
    {
        dp[i][1] = minDist[1][i];
        dp[i][i] = 0;
    }
    for (int i = 2; i <= n;i++)
    {
        for (int j = 2; j <= min(i - 1,m);j++)
        {
            for (int k = j-1; k < i;k++)
            {
                dp[i][j] = min(dp[i][j],dp[k][j-1]+minDist[k+1][i]);
            }
        }
    }

    cout << dp[n][m]<<endl;
    
    return 0;
}