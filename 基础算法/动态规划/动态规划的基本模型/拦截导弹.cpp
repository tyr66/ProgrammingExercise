#include<iostream>

using namespace std;

int dp[1001][2];
int arr[1001];
int sys[1001];

void print(int idx)
{

}

int main()
{
    int v;
    int count = 0;
    int n = 1;
    int maxLen = 0;
    while(cin>>v)
    {
        int k = 0;
        arr[n] = v;
        dp[n][1] = 1;

        for (;k<count;k++)
        {
            if(v<=sys[k])
                break;
        }

        sys[k] = v;
        if(k ==count)
            count++;

        for (int i = n - 1; i >= 1;i--)
        {
            if(arr[n]<=arr[i]&&dp[n][1]<dp[i][1]+1)
            {
                dp[n][0] = i;
                dp[n][1] = dp[i][1]+1;
            }
        }

        maxLen = max(maxLen,dp[n][1]);

        n++;
    }

    cout << maxLen << endl;
    cout << count << endl;

    return 0;
}