#include<iostream>
#include<stack>
using namespace std;

int dp[201][2];
int arr[201];

void print(int idx)
{
    if(idx == -1)
        return;

    print(dp[idx][0]);
    printf("%d ",arr[idx]);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n;i++)
    {
        cin >> arr[i];
        dp[i][0] = -1;
        dp[i][1] = 1;
    }

    int maxLen = 1;
    int maxIdx = 0;
    for (int i = 0; i < n;i++)
    {
        for (int j = i-1; j >= 0;j--)
        {
            if(arr[i]>=arr[j]&&dp[j][1]+1>dp[i][1])
            {
                dp[i][1] = dp[j][1]+1;
                dp[i][0] = j;
            }
        }

        if(maxLen<dp[i][1])
        {
            maxLen = dp[i][1];
            maxIdx = i;
        }
    }

    printf("max=%d\n",maxLen);
    print(maxIdx);

    return 0;
}