#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;


/**
 * @
 * 使用prime算法可能出现的问题
 * 1.优先队列中弹出的边可能并不是到当前最小生成距离最小的边
 * 2.在最小生成树上添加重复链接的边
 */


struct Edge
{
    int type;
    int from;
    int to;
    int w;
    bool operator<(const Edge&e) const
    {
        return e.w > w;
    }

};

vector<Edge> edges;
bool isVis[2001];
int parent[2001];
int N;
int M;

int get_parent(int i)
{
    if(i == parent[i])
        return i;
    parent[i] = get_parent(parent[i]);
    return parent[i];
}

void Union(int i,int j)
{
    int i_par = get_parent(i);
    int j_par = get_parent(j);

    if(i_par!=j_par)
    {
        parent[i_par] = j_par;
    }
}

int Kruskal()
{
    sort(edges.begin(),edges.end());

    int res = 0;
    int cnt = 0;
    int idx = 0;

    for (int i = 0; i < M;i++)
    {
        Edge e = edges[i];

        if(get_parent(e.from)!=get_parent(e.to))
        {
            Union(e.from,e.to);
            res += e.w;
        }

    }

        return res;
} 


int main()
{
    cin >> N>>M;
    int sum =0;

    for (int i = 1; i <= N;i++)
        parent[i] = i;

        for (int i = 1; i <= M; i++)
        {
            int type, from, to, w;
            cin >> type >> from >> to >> w;

            edges.push_back({type,from,to,w});

            if (type == 1)
            {
                Union(from, to);
                sum += w;
            }
        }

    sum+=Kruskal();

  
    cout << sum << endl;

    return 0;
}