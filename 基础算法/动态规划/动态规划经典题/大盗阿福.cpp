#include<iostream>

using namespace std;

int dp[100001];
int arr[100001];

int main()
{
    int N,T;
    cin >> T;

    while(T>0)
    {
        cin >> N;

        for (int i = 1; i <= N;i++)
        {
            cin >> arr[i];
        }

        dp[1] = arr[1];
        for (int i = 2; i <= N;i++)
        {
            dp[i] = max(dp[i-1],dp[i-2]+arr[i]);
        }

        cout << dp[N]<<endl;

        T--;
    }

    
    return 0;
}