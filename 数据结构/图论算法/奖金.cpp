#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/**
 * 思路：拓扑排序(基于顶点入度宽的度优先搜索或者是深度优先搜索的逆后序实现)
 * 
 */


bool isVis[10001];
int in_degree[10001];
vector<int> adj[10001];


int main()
{
    int n, m;
    cin >> n >> m;

    int from, to;
    for (int i = 1; i <= m;i++)
    {
        cin >> to >> from;
        adj[from].push_back(to);
        in_degree[to]++;
    }

    queue<int> que;
    for (int i = 1; i <= n;i++)
    {
        if(in_degree[i] == 0)
        {
            que.push(i);
            isVis[i] = true;
        }
    }

    int bonus = 100;
    int totalBonus = 0;
    int count = que.size();
    int nums = 0;

    while(!que.empty())
    {
        int n = que.front();
        que.pop();

        totalBonus += bonus;
        nums++;

        for (int i = 0; i < adj[n].size();i++)
        {
            if(isVis[adj[n][i]])
            {
                continue;
            }

            in_degree[adj[n][i]]--;

            if(in_degree[adj[n][i]] == 0)
            {
                isVis[adj[n][i]] = true;
                que.push(adj[n][i]);
            }
        }

        if(--count == 0)
        {
            bonus++;
            count = que.size();
        }
    }

    if(nums == n)
        cout << totalBonus << endl;
    else
        cout << "Poor Xed\n";
    return 0;
}