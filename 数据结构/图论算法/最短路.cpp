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
vector<Edge> edges[100001];
int cost[100001];
bool isChecking[100001];

void spfa(int N,int S)
{
    memset(cost,0x3f,sizeof(cost));
    cost[S] = 0;
    queue<int> que;
    isChecking[S] = true;
    que.push(S);

    while(!que.empty())
    {
        int n = que.front();
        que.pop();
        isChecking[n] = false;

        for (int i = 0; i < edges[n].size();i++) {
            int from = n;
            int to = edges[n][i].to;
            int w = edges[n][i].w;

            if(cost[to]>cost[from]+w) {

                cost[to] = cost[from] + w;
                
                if(!isChecking[to]) {
                    que.push(to);
                    isChecking[to] = true;
                }
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

    spfa(N,1);

    cout << cost[N]<<endl;

    return 0;
}