#include <iostream>
#include <math.h>
using namespace std;

/**
 * 思路：先使用floyed算法求出各点到各点的最短路径，
 * 对于每一个牧场，获取从该点出发的最大牧场距离max_cost[i]
 * 然后对于每一个牧区枚举将它不可达的点一一进行联通后的最大牧场距离，并从中选出最小值minMaxCost
 * 从minMaxCost和max_cost[i]中选出最大值，这是因为即使是将两个牧场联通后，得到的最大牧场距离可能比原来
 * 未联通的小。
 */

const double I_MAX = 0x7ffffff;

struct Point
{
    double x;
    double y;
};
double cost[151][151];
Point points[151];
double max_cost[151];

double get_dist(int from, int to)
{
    return sqrt(pow(points[from].x - points[to].x, 2) + pow(points[from].y - points[to].y, 2));
}

int main()
{
    int N;
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    char flag;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            cin >> flag;
            if (flag == '1')
            {
                cost[i][j] = get_dist(i, j);
            }
            else
            {
                cost[i][j] = I_MAX;
            }
        }
        cost[i][i] = 0;
    }

    /*  for (int i = 1; i <= N;i++)
    {
        for (int j = 1; j <= N;j++)
        {
            if(cost[i][j]!=I_MAX)
                cout << cost[i][j] << " ";
            else
                cout << "# ";
        }
        cout << endl;
    }  */

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j]);
            }
        }
    }


    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if(cost[i][j]!=I_MAX)
                max_cost[i] = max(max_cost[i], cost[i][j]);
        }
    }

    double minMaxCost = I_MAX;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (cost[i][j] == I_MAX)
            {
                minMaxCost = min(minMaxCost, max_cost[i] + max_cost[j] + get_dist(i, j));
            }
        }
    }

    double res = 0;
    for (int i = 1; i <= N; i++)
    {
        //printf("%.6f\n", max_cost[i]);
        res = max(res, max_cost[i]);
    }

    printf("%.6f\n", max(res,minMaxCost));

    return 0;
}