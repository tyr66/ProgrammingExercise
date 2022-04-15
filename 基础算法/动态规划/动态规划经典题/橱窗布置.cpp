#include<iostream>

using namespace std;

int dp[101][101];
int mat[101][101];
int record[101][101];

void print(int k,int m)
{
    if(k==0)
        return;


    print(k-1,record[k][m]-1);

    printf("%d ",record[k][m]);
}

int main()
{
    int M, N;
    cin >> M >> N;

    for (int i = 1; i <= M;i++)
    {
        for (int j = 1; j <= N;j++)
        {
            cin >> mat[i][j];
            dp[i][j] = -0x3f3f3f3f;
        }
    }

    for (int j = 0; j <= N;j++)
        dp[0][j] = 0;

        for (int i = 1; i <= M; i++)
        {
            for (int j = i; j <= N; j++)
            {
                for (int l = i - 1; l < j; l++)
                {
                    if (dp[i - 1][l] + mat[i][l + 1] > dp[i][j])
                    {
                        dp[i][j] = dp[i - 1][l] + mat[i][l + 1];
                        record[i][j] = l + 1;
                    }

                    // dp[i][j] = max(dp[i][j],dp[i-1][l]+mat[i][l+1]);
                }
            }
        }

    cout << dp[M][N]<<endl;
    print(M,N);

    return 0;
}