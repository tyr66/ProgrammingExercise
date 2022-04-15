#include<iostream>
#include<string>
#include<cstring>
using namespace std;

/**
 * 思路 ：动态规划
 *            - dp[i-1][j-1]        ,当a[i] == b[j] 时 
 * dp[i][j] = - dp[i-1][j]+1        ,当a[i] != b[j]，并且此时选择删除 a[i]
 *            - dp[i][j-1]+1        ,当a[i] != b[j],并且此时选择在a[i]后面添加一个b[j]
 *            - dp[i-1][j-1]+1      ,当a[i] != b[j],并且此时选择修改a[i]
 */

int dp[2001][2001];

int min3(int a,int b,int c)
{
    if(a>b)
    {
        return c > b ? b : c;
    }

    return c > a ? a : c;
}


int main()
{
    string a, b;
    cin >> a >> b;

    memset(dp,127,sizeof(dp));

    //初始化dp数组
    dp[0][0] = 0;
    for (int i = 1; i <= a.size();i++)
    {
        dp[i][0] = i;
    }

    for (int j = 1; j <= b.size();j++)
    {
        dp[0][j] = j;
    }

        for (int i = 1; i <= a.size(); i++)
        {
            for (int j = 1; j <= b.size(); j++)
            {
                if (a[i - 1] == b[j - 1])
                {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else
                {
                    dp[i][j] = min3(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]) + 1;
                }
            }
        }

    cout << dp[a.size()][b.size()]<<endl;

    return 0;
}