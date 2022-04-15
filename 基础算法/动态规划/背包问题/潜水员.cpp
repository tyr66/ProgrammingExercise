#include<iostream>
#include<cstring>
using namespace std;

int dp[22][80];
int O[1001];
int N[1001];
int W[1001];
int m, n;
int K;

void cal()
{
    
}

int main()
{
    cin >> m >> n;
    cin >> K;

    for (int i = 1; i <= K;i++)
        cin >> O[i]>>N[i]>>W[i];


    memset(dp,127,sizeof(dp));
    dp[0][0] = 0;

    int c_i, c_j;
    for (int k = 1; k <= K;k++)
    {
        //为防止同一层中已经计算过的项，影响下一项的计算，因此i和j要从后往前遍历
        for (int i = m; i>=0;i--)
        {
            for (int j = n; j >= 0;j--)
            {
                c_i = max(0,i-O[k]);
                c_j = max(0,j-N[k]);

                dp[i][j] = min(dp[i][j],dp[c_i][c_j]+W[k]);
            }
        }
    }

    cout << dp[m][n]<<endl;
    return 0;
}