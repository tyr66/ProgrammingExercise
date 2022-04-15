#include<iostream>
#include<vector>
#include<iomanip>
using namespace std;

const double INF = 0x7fffffff;

struct Edge
{
    int from;
    int to;
    double discount;
};

vector<Edge> edges[2001];
double cost[2001];

int main()
{
    int N,M;
    cin >> N >> M;


    for (int i = 1; i <= M;i++)
    {
        int from, to;
        double discount;

        cin >> from >> to >> discount;

        discount = 1 / (1-discount/100.0);

        edges[from].push_back({from,to,discount});
        edges[to].push_back({to,from,discount});
    }

    int src, tar;
    cin >> src >> tar;

    bool flag;
    for (int i = 1; i <= N;i++)
        cost[i] = INF;
    cost[src] = 100;

    while (true)
    {
        flag = false;

        for (int i = 1; i <= N;i++)
        {
            for (int j = 0; j < edges[i].size();j++)
            {
                int to = edges[i][j].to;

                if(cost[i]==INF)
                    break;;

                double fee = cost[i] * edges[i][j].discount;

                if(fee<cost[to])
                {
                    cost[to] = fee;
                    flag = true;
                }
            }
        }

        if (!flag)
            break;
    }

    printf("%.8lf\n",cost[tar]);

    return 0;
}