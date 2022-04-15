#include<iostream>

using namespace std;

int dp[6001];
int w[501];
int v[501];
int nums[501];

int main()
{
    int M, N;
    cin >> N >> M;

    for (int i = 1; i <= N;i++)
    {
        cin >> w[i]>>v[i]>>nums[i];
    }

    for (int i = 1; i <= N;i++)
    {
        //从后往前进行遍历更为简便
        for (int j = M; j >0;j--)
        {
            for (int k = 0; k <= nums[i];k++)
            {
                if(j-k*w[i]<0)
                    break;
                dp[j] = max(dp[j],dp[j-k*w[i]]+v[i]*k);
            }
        }
    }
    
    printf("%d\n",dp[M]);

    return 0;
}