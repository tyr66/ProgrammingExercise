#include<iostream>

using namespace std;

int dp[1000];
int arr[1000];

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N;i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N;i++)
    {
        dp[i] = arr[i];

        for (int j = 0; j < i;j++)
        {
            if(arr[i]>arr[j])
            {
                dp[i] = max(dp[i],dp[j]+arr[i]);
            }
        }
    }

    int res = (-2147483647 - 1);
    for (int i = 0; i < N;i++)
    {
        res = max(res,dp[i]);
    }

    cout << res << endl;

    return 0;
}