#include <iostream>

using namespace std;

/**
 * 思路：开始以为可以直接使用DFS但是后来发现，题目原来是有向图DFS失败，然后就想将图改为无向图但是发现不行，
 * 改成无向图后无向图中连图的子图可能对应到有向图中可能无法通过一个顶点来进行遍历。例如
 * 2->1,3-1，这个子图转化为无向图后可以使用一个顶点来完成遍历，但是对应的有向图却至少需要两个顶点来完成遍历。
 * 这道题可以使用Floyd 算法或者是tarjan算法来求解
 */

int adjMat[201][201];
int parent[201];
int N;

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        int to;
        while (cin >> to && to != 0)
        {
            adjMat[i][to] = 1;
        }
    }

    for (int k = 1; k <= N; k++)
    {
        for (int i = 1; i <= N; i++)
        {
            for (int j = 1; j <= N; j++)
            {
                if (adjMat[i][k] && adjMat[k][j])
                {
                    adjMat[i][j] = 1;
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            if (adjMat[i][j])
                parent[j] = parent[i];
    }

    int res = 0;

    for (int i = 1; i <= N; i++)
        if (parent[i] == i)
            res++;

    cout << res << endl;

    return 0;
}