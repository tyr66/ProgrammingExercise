#include<iostream>
#include<cstring>
using namespace std;

/**
 * 思路
 * 思路和合唱队列差不多，先求[1~n]从左到右的买卖一次的最大值，然后求出从[n~1]从右到左买卖一次的最大值
 * 最后求两者和的最大值
 */


int arr[100001];
int left_DP[100002];
int right_DP[100002];


int main()
{
    int T,N;
    cin >> T;

    while(T>0)
    {
        cin >> N;

        for (int i = 1; i <= N;i++)
            cin >> arr[i];

        //memset(dp,0,sizeof(dp));
        int min_nums = 0x3f3f3f3f;
        left_DP[0] = 0;
        for (int i = 1; i <= N;i++)
        {
            min_nums = min(min_nums,arr[i]);
            left_DP[i] = max(left_DP[i - 1], arr[i] - min_nums);
        }

        int max_num = -0x3f3f3f3f;
        right_DP[N] = 0;
        right_DP[N + 1] = 0;
        for (int i = N; i >= 1;i--)
        {
            max_num = max(max_num,arr[i]);
            right_DP[i] = max(right_DP[i+1],max_num - arr[i]);
        }

        long long res = 0;
    
        for (int i = 1; i <= N;i++)
        {
            res = max(res,(long long)left_DP[i]+right_DP[i]);
        }

        cout << res << endl;

        
        T--;
    }

    return 0;
}