#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct Edge
{
    int from;
    int to;
    int w;

    bool operator<(const Edge&p) const
    {
        return p.w < w;
    }
};

vector<Edge> adj[101];
bool isVis[101];
int path[101];

int prime()
{
    int res = 0;
    priority_queue<Edge> pq;
    pq.push({0,1,0});

    while (!pq.empty())
    {
        int from = pq.top().from;
        int to = pq.top().to;
        int w = pq.top().w;
        pq.pop();

        if(isVis[to])
            continue;
        isVis[to] = true;
        path[to] = from;
        res += w;
        for (int i = 0; i < adj[to].size();i++)
        {
            if(isVis[adj[to][i].to])
                continue;
            pq.push({to,adj[to][i].to,adj[to][i].w});
        }
    }

    return res;
}

int main()
{

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= m;i++)
    {
        int from, to, w;
        cin >> from >> to >> w;

        adj[from].push_back({from,to,w});
        adj[to].push_back({to,from,w});
    }

    prime();

    for (int i = 2; i <= n;i++)
    {
        printf("%d %d\n",path[i],i);
    }

        return 0;
}