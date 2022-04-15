#include<iostream>
#include<vector>

using namespace std;

int arr[1001];
int dp[1001];

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n;i++)
    {
        int tmp = dp[0];
        for (int j = 1; j <= i;j++)
        {
            cin >> arr[j];
            int val = dp[j];
            dp[j] = arr[j] + max(dp[j],tmp);
            tmp = val;
        }
    }

    int maxNum = (-2147483647 - 1);
    for (int i = 1; i <= n;i++)
    {
        maxNum = max(dp[i],maxNum);
    }

    cout << maxNum<<endl;
    return 0;
}