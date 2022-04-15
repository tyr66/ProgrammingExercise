#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;

struct Edge
{
    int to;
    int w;

    bool operator<(const Edge&e) const
    {
        return e.w < w;
    }
};

int cost[2001];
vector<Edge> edges[2001];
bool isVis[2001];

void Dijkstra(int N,int s,int t)
{
    memset(cost,0x3f,sizeof(cost));
    cost[s] = 0;
    priority_queue<Edge> que;
    que.push({s,0});

    while(!que.empty())
    {
        Edge e = que.top();
        que.pop();

        if(isVis[e.to])
            continue;
        isVis[e.to] = true;

        for (int i = 0; i < edges[e.to].size();i++)
        {
            int from = e.to;
            int to = edges[from][i].to;
            int w = edges[from][i].w;

            if(cost[to]>cost[from]+w)
            {
                cost[to] = cost[from] + w;
                que.push({to,cost[to]});
            }
        }
    }
}

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < M;i++)
    {
        int from, to, w;
        cin >> from >> to >> w;

        edges[from].push_back({to,w});
        edges[to].push_back({from,w});
    }

    Dijkstra(N,1,N);

    cout << cost[N] << endl;

    return 0;
}