#include<iostream>

using namespace std;

/**
 * 思路：
 * 设置两个dp数组，nums_DP用来求解最大收服数，damage_DP用来求解造成的最小伤害值
 * 
 * 对于nums_DP 状态转移方程为：
 *                  - nums_DP[n - cost[i]][m - damage[i]] + 1   ,当 nums_DP[n-cost[i]][m-damage[i]]+1 > nums_DP[n][m] 时
 * nums_DP[n][m] =  -
 *                  - nums_DP[n][m]                             ,当 nums_DP[n-cost[i]][m-damage[i]]+1 <= nums_DP[n][m] 时
 * 
 * 对于damage_DP 状态转移方程为：
 *                   - damage_DP[n - cost[i]][m - damage[i]] + damage[i]                    ,当nums_DP[n-cost[i]][m-damage[i]]+1 > nums_DP[n][m]时
 * damage_DP[n][m] = - min(damage_DP[n][m],damage_DP[n-cost[i]][m-damage[i]]+damage[i])     ,当nums_DP[n-cost[i]][m-damage[i]]+1 == nums_DP[n][m]
 *                   - damage_DP[n][m]                                                      ,当nums_DP[n-cost[i]][m-damage[i]]+1 < nums_DP[n][m]
 */


int nums_DP[1001][501];
int damage_DP[1001][501];
int cost[101];
int damage[101];

int main()
{
    int N, M, K;
    cin >> N >> M >> K;

    for (int i = 1; i <= K;i++)
        cin >> cost[i]>>damage[i];

    for (int i = 1; i <= K;i++)
    {
        for (int n = N; n >= cost[i];n--)
        {
            for (int m = M; m > damage[i];m--)
            {
                if(n-cost[i]<0||m-damage[i]<=0)
                    break;
                
                if(nums_DP[n-cost[i]][m-damage[i]]+1>nums_DP[n][m])
                {
                    nums_DP[n][m] = nums_DP[n - cost[i]][m - damage[i]] + 1;
                    damage_DP[n][m] = damage_DP[n - cost[i]][m - damage[i]] + damage[i];

                }else if(nums_DP[n-cost[i]][m-damage[i]]+1==nums_DP[n][m])
                {
                    damage_DP[n][m] = min(damage_DP[n][m],damage_DP[n-cost[i]][m-damage[i]]+damage[i]);
                }
            }
        }
    }

    cout << nums_DP[N][M]<<" "<<(M - damage_DP[N][M])<<endl;

    return 0;
}