#include<iostream>
#include<queue>
#include<vector>
using namespace std;

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

vector<Edge> edges[301];
bool isVis[301];
int N;
int maxEdge;

int prime()
{
    int res = 0;

    priority_queue<Edge> pq;
    pq.push({0,1,0});

    while(!pq.empty())
    {
        int from = pq.top().to;
        int w = pq.top().w;
        pq.pop();

        if(isVis[from])
            continue;

        isVis[from] = true;
        res += w;
        maxEdge = max(maxEdge,w);

        for (int i = 0; i < edges[from].size();i++)
        {
            int to = edges[from][i].to;

            if(!isVis[to])
            {
                pq.push(edges[from][i]);
            }
        }
    }

    return res;
}


int main()
{
    int M;
    cin >> N>>M;

    for (int i = 1; i <= M;i++)
    {
        int from, to, w;
        cin >> from >> to >> w;

        edges[from].push_back({from,to,w});
        edges[to].push_back({to, from, w});
    }

    prime();

    cout << N - 1 << " " << maxEdge << endl;

    return 0;
}