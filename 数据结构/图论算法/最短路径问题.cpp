#include<iostream>
#include<math.h>
#include<vector>
using namespace std;

const int I_MAX = 2147483647;

struct Point
{
    double x;
    double y;
};

struct Edge
{
    int from;
    int to;
    double w;
};

vector<Edge> edges[101];
Point points[101];
double cost[101];


Edge buildEdge(int from,int to)
{
    Edge edge;
    edge.from = from;
    edge.to = to;
    edge.w = sqrt(pow(points[from].x - points[to].x,2)+pow(points[from].y - points[to].y,2));
    return edge;
}

int main()
{
    int N,M;
    cin >> N;

    for (int i = 1; i <= N;i++)
    {
        cin >> points[i].x >> points[i].y;
    }
    cin >> M;

    for (int i = 1; i <= M;i++)
    {
        int from, to;
        cin >> from >> to;
        edges[from].push_back(buildEdge(from, to));
        edges[to].push_back(buildEdge(to,from));
        //cout << e.w << endl;
    }



    int src, tar;
    cin >> src >> tar;

    bool flag = false;

    for (int i = 1; i <= N;i++)
        cost[i] = I_MAX;
    cost[src] = 0;

    while (true)
    {
        flag = false;

        for (int i = 1; i <= N; i++)
        {
            for (int j = 0; j < edges[i].size(); j++)
            {
                Edge &e = edges[i][j];

                if (cost[i]!=I_MAX&&cost[i]+edges[i][j].w<cost[e.to])
                {
                    cost[e.to] = cost[i] + edges[i][j].w;
                    flag = true;
                }
            }
        }

        if (!flag)
            break;
    }

    printf("%.2f",cost[tar]);

    return 0;
}