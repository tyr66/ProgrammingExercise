#include<iostream>

using namespace std;

//01背包

int dp[1001];
int arr[21];

int main()
{
    int N, T;
    cin >> N >> T;

    for (int i = 1; i <= N;i++)
    {
        cin >> arr[i];
    }

    dp[0] = 1;

    for (int i = 1; i <= N;i++)
    {
        for (int j = T; j >= arr[i];j--)
        {
            dp[j] = dp[j] + dp[j-arr[i]];
        }
    }

    cout << dp[T]<<endl;

    return 0;
}