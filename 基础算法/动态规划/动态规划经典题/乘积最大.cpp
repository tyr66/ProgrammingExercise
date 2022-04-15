#include<iostream>

using namespace std;

int dp[11][8];
int arr[11];
int nums[11][11];

int main()
{

    int N, K;
    cin >> N >> K;

    string str;
    cin >> str;

    for (int i = 0; i < str.size();i++)
    {
        arr[i + 1] = (str[i] - '0');
    }

   
    for (int i = 1; i <= N;i++)
    {
        for (int j = i; j <= N;j++)
        {
            nums[i][j] = nums[i][j-1]*10+arr[j];
        }
        dp[i][0] = nums[1][i];
    }

        for (int k = 1; k <= K; k++)
        {
            for (int j = k+1; j <= N;j++)
            {
                for (int i = j;i>k;i--)
                {
                    dp[j][k] = max(dp[i-1][k-1]*nums[i][j],dp[j][k]);
                }
            }
        }

        cout << dp[N][K];

        return 0;
}