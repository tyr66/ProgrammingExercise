#include<iostream>

using namespace std;

/**
 * 思路：动态规划
 * dp数组为dp[i][j]，表示时间j下，到达第i个池塘时，最多可以钓到的鱼的数量
 * 状态转移方程为：
 * 
 * dp[i][j] = max(dp[i][j],dp[i-1][j-pond[i-1][2]-k]+sum) 并且k要满足j - (pond[i-1][2])-k>=path-pond[i-1][2]，k = [0,1,......]
 * 其中path为到达第i个池塘总共要花费的时间，pond[i-1][2] 表示从第i-1个池塘到达第i个池塘所要花费的时间，k为在第i个池塘钓鱼的次数
 * sum为在第i个池塘进行了k次钓鱼时总共可以钓到的次数。
 */


int pond[101][3];
int dp[101][1001];

int main()
{
    int N,T;
    cin >> N;
    for (int i = 0; i < 3;i++)
    {
        for (int j = 1; j <= N;j++)
        {
            cin >> pond[j][i];
        }
    }

    T = pond[N][2];
    pond[N][2] = 0;
    int res = 0;
    int sum = 0;
    int path = 0;
    for (int i = 1; i <= N; i++)
    {
        
        for (int j = 1; j <= T; j++)
        {
            if(j<=path)
                continue;

            
            dp[i][j] = dp[i - 1][j - pond[i - 1][2]];
            sum = pond[i][0];
            for (int k = 1; pond[i][0]-pond[i][1]*(k-1) > 0; k++,sum += (pond[i][0] - pond[i][1]*(k-1)))
            {
                if (j - (pond[i-1][2])-k<path-pond[i-1][2])//要保证剩余的时间可以到达i-1的位置上
                    break;
                dp[i][j] = max(dp[i][j], dp[i - 1][j-(pond[i-1][2])-k]+sum);
            }


            res = max(res,dp[i][j]);
        }

        path += pond[i][2];
    }

    /* for (int i = 1; i <= N;i++)
    {
        for (int j = 1; j <= T;j++)
        {
            cout << dp[i][j]<<" ";
        }
        cout << endl;
    } */

    cout << res << endl;

    return 0;
}