#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
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

const int INF = 0x3f3f3f3f;
int T, C;
vector<Edge> edges[6201];
int cost[6201];

void Dijkstra(int ts,int td)
{
    priority_queue<Edge> que;
    memset(cost, 0x3f, sizeof(cost));
    cost[ts] = 0;
    que.push({ts,0});

    while(!que.empty())
    {
        Edge e = que.top();
        que.pop();

        if(e.w>cost[e.to])
            continue;

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
    int ts, td;
    cin >> T >> C;
    cin >> ts >> td;

    for (int i = 0;i<C;i++)
    {
        int from, to, w;
        cin >> from >> to >> w;
        edges[from].push_back({to,w});
        edges[to].push_back({from,w});
    }


    Dijkstra(ts,td);

    cout << cost[td]<<endl;

    return 0;
}