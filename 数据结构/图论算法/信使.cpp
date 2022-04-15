#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/**
 * 注意：该题需要求的是所需最小的完成时间，而不是求最小的完成的工作量
 */

struct Edge
{
    int from;
    int to;
    int w;

    bool operator<(const Edge&e) const
    {
        return e.w < w;
    }
};

int N, M;
int cost[101][101];
const int INF = 0x3f3f3f3f;

int main()
{

    cin >> N >> M;

    for (int i = 1; i <= N;i++)
    {
        for (int j = 1; j <= N;j++)
        {
            cost[i][j] = INF;
        }

        cost[i][i] = 0;
    }

    for (int i = 0; i < M; i++)
    {
        int from, to, w;
        cin >> from >> to >> w;

        cost[from][to] = w;
        cost[to][from] = w;
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N;i++)
        {
            for (int j = 1; j <= N;j++)
            {
                cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
            }
        }
    }

    int max_val = 0;
    for (int i = 1; i <= N;i++)
    {
        max_val = max(max_val,cost[1][i]);
    }

    if(max_val == INF)
        cout << "-1" << endl;
    else
        cout << max_val << endl;

        return 0;
}