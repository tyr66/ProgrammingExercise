#include<iostream>

using namespace std;

int w[301];
int v[301];
int groups[11][301];
int dp[201];

int main()
{
    int W, N, T;
    cin >> W >> N >> T;

    for (int i = 1; i <= N;i++)
    {
        int p;
        cin >> w[i] >> v[i] >> p;

        groups[p][++groups[p][0]] = i;
    }

    for (int i = 0; i <= T;i++)
    {
        if(groups[i][0] == 0)
            continue;
        
        for (int j = W; j >= 0;j--)
        {
            for (int k = 1; k <= groups[i][0];k++)
            {
                if(j<w[groups[i][k]])
                    continue;
                dp[j] = max(dp[j],dp[j-w[groups[i][k]]]+v[groups[i][k]]);
            }
        }
    }

    cout << dp[W]<<endl;

    return 0;
}