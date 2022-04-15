#include<iostream>
#include<vector>
using namespace std;

int cows[801];
int cost[801][801];

int main()
{
    int N, P, C;
    cin >> N >> P >> C;

    for (int i = 1; i <= N;i++)
        cin >> cows[i];

    for (int i = 1; i <= P;i++)
    {
        for (int j = 1; j <= P;j++)
        {
            cost[i][j] = 0x3f3f3f3f;
        }
        cost[i][i] = 0;
    }

    for (int i = 1; i <= C; i++)
    {
        int from, to, w;
        cin >> from >> to >> w;

        cost[from][to] = w;
        cost[to][from] = w;
    }



    for (int k = 1; k <= P; k++)
    {
        for (int i = 1; i <= P; i++)
        {
            for (int j = 1; j <= P; j++)
            {
                cost[i][j] = min(cost[i][j],cost[i][k]+cost[k][j]);
            }
        }
    }

    int res = 0x3f3f3f3f;

    for (int i = 1; i <= P;i++)
    {
        int sum = 0;
        for (int j = 1; j <= N;j++)
        {
            sum += cost[cows[j]][i];
        }

        res = min(res,sum);
    }

    cout << res << endl;

        return 0;
}