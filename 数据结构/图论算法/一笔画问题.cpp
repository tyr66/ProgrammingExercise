#include <iostream>

using namespace std;
const int N = 1001;
int edges[N][N];
int w[N];
int path[N];
int n, m;
int idx;

void dfs(int from)
{
    path[++idx] = from;

    for (int to = 1; to <= n; to++)
    {
        if (edges[from][to])
        {
            edges[from][to] = 0;
            edges[to][from] = 0;
            dfs(to);
        }
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 1; i <= m; i++)
    {
        int from, to;
        cin >> from >> to;
        edges[from][to] = 1;
        edges[to][from] = 1;
        w[from]++;
        w[to]++;
    }

    int origion = 1;
    for (int i = 1; i <= n; i++)
    {
        if (w[i] % 2 == 1)
        {
            //奇点
            origion = i;
            break;
        }
    }

    dfs(origion);

    for (int i = 1;i<=idx;i++)
        cout << path[i]<<" ";

        return 0;
}