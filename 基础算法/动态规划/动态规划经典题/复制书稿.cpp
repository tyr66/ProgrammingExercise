#include<iostream>
#include<cstring>
using namespace std;

int dp[501][501];
int books[501];
int sum[501][501];

/*
9 4
1 2 3 4 5 6 7 8 9
*/

void print(int k,int m)
{
    if(k ==0)
        return;
    if(k==1)
    {
        printf("%d %d\n",k,m);
        return;
    }

    int t = m;
    int s = books[m];

    while(s+books[t-1]<=dp[k][m])
    {
        s += books[t-1];
        t--;
    }

    print(k-1,t-1);

    printf("%d %d\n",t,m);
}


int main()
{

    int m, k;
    cin >> m >> k;

    for (int i = 1; i <= m;i++)
    {
        cin >> books[i];
    }

    memset(dp,0x3f3f3f3f,sizeof(dp));

    for (int i = 1; i <= m;i++)
    {
        for (int j = i; j <= m; j++)
        {
            sum[i][j] = sum[i][j-1]+books[j];
        }
    }

    for (int i = 1; i <= m;i++)
    {
        dp[1][i] = sum[1][i];
    }

    for (int i = 2; i <= k; i++)
    {
        //需要尽可能让前面的人少抄
        for (int j = 1; j <= m; j++)
        {
            for (int l = i - 1; l < j ; l++)
            {
                    dp[i][j] = min(max(dp[i - 1][l], sum[l + 1][j]),dp[i][j]);
                
            }
        }
    }

    print(k,m);

    //cout << dp[k][m];

    return 0;
}