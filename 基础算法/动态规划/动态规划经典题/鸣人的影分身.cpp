#include<iostream>

using namespace std;

int dp[11][11];

int F(int M,int N)
{
    if(M==0||N==1)
        return 1;

    if(M>=N)
        return F(M, N - 1) + F(M - N, N);

    return F(M,N-1);
}

int main()
{
    int T;
    int M, N;
    cin >> T;

    while(T>0)
    {
        cin >> M >> N;

        for (int j = 0; j <= N;j++)
        {
            dp[0][j] = 1;
        }
        for (int i = 0; i <= M;i++)
        {
            dp[i][1] = 1;
        }

        for (int i = 1; i <= M; i++)
        {
            for (int j = 2; j <= N; j++)
            {
                if (i >= j)
                {
                    dp[i][j] = dp[i][j - 1] + dp[i - j][j];
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        cout << dp[M][N]<<endl;

        T--;
    }

    return 0;
}