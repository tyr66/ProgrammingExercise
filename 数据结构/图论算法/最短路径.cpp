#include<iostream>
#include<queue>
#include<string>
#include<cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
int adjMat[81][81];
int cost[81];

struct Pair
{
    int idx;
    int cost;

    bool operator<(const Pair&p) const
    {
        return p.cost < cost;
    }
};

void Dijkstra(int N,int V)
{
    memset(cost,0x3f,sizeof(cost));
    cost[V] = 0;

    priority_queue<Pair> que;
    que.push({V,0});

    while(!que.empty())
    {
        auto p = que.top();
        que.pop();

        if(cost[p.idx]<p.cost)
            continue;

        for (int i = 1; i <= N;i++)
        {
            //不可达
            if(adjMat[p.idx][i]==INF)
                continue;
            
            if(cost[p.idx]+adjMat[p.idx][i]<cost[i])
            {
                cost[i] = cost[p.idx] + adjMat[p.idx][i];
                que.push({i,cost[i]});
            }
        }
    }

    for (int i = 1; i <= N;i++)
    {
        if(i!=V)
        {
            printf("(%d -> %d) = %d\n",V,i,cost[i]);
        }
    }
}


int main()
{
    int N;
    int V;
    string str;

    cin >> N >> V;

    for(int i=1;i<=N;i++){//输入图，注意判断整数和字符
        for(int j=1;j<=N;j++){
            int c;
            if(scanf("%d",&c)==1) adjMat[i][j]=c;
            else adjMat[i][j]=INF;
         }
    }

     /* for (int i = 1; i <= N;i++)
    {
        for (int j = 1; j <= N;j++)
        {
            if(adjMat[i][j]!=INF)
            cout << adjMat[i][j] << " ";
            else
                cout << "INF ";
        }

        cout << endl;
    }
  */

    Dijkstra(N,V);

    return 0;
}