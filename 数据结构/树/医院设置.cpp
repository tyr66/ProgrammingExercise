#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

/**
 * 思路：层序遍历
 * 
 */

int nodes[101];
bool mark[101];
vector<vector<int>> adj;

int bfs(int n)
{

    int level = 0;
    int count = 1;
    int sum = 0;
    queue<int> que;

    que.push(n);
    mark[n] = true;

    while(!que.empty())
    {
        n = que.front();
        que.pop();

        sum += level * nodes[n];

        for (int i = 0; i < adj[n].size();i++)
        {
            int to = adj[n][i];

            if(mark[to])
                continue;

            que.push(to);
            mark[to] = true;
        }

        if(--count == 0)
        {
            count = que.size();
            level++;
        }
    }

    return sum;
}


int main()
{
    int N,res = 2147483647;
    int left,right;
    cin >> N;

    adj.resize(N+1);
    for (int i = 1;i <= N;i++)
    {
        cin >> nodes[i] >> left >> right;

        if(left!=0)
        {
            adj[i].push_back(left);
            adj[left].push_back(i);
        }

        if(right!=0)
        {
            adj[i].push_back(right);
            adj[right].push_back(i);
        }
    }

    for (int i = 1; i <= N;i++)
    {
        res = min(res,bfs(i));

        memset(mark,0,sizeof(mark));
    }

    cout << res << endl;

    return 0;
}