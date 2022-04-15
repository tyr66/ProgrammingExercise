#include<iostream>

using namespace std;

int dp[11][16];
int plan[11][16];
int mat[11][16];
int N, M;

/*
3 3
30 40 50
20 30 50
20 25 30
*/

void print(int i,int j)
{
    if(i==0)
    {
        return;
    }

    print(i-1,j - plan[i][j]);
    printf("%d %d\n",i,plan[i][j]);
}

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N;i++)
    {
        for (int j = 1; j <= M;j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            for (int k = 0; k <= j; k++)
            {
                if(dp[i - 1][ k] + mat[i][j-k]>dp[i][j])
                {
                    dp[i][j] = dp[i - 1][ k] + mat[i][j-k];
                    plan[i][j] = j-k;
                }
            }
        }
    }

    cout << dp[N][M]<<endl;
    print(N,M);

    return 0;
}