#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> edges[101];

int in_degree[101];
bool isVis[101];
int N;

int main()
{
    cin >> N;

    for (int i = 1; i <= N;i++)
    {
        int to;
        while(true)
        {
            cin >> to;
            if(to ==0)
                break;
            edges[i].push_back(to);
            in_degree[to]++;
        }
    }


    queue<int> que;

    for (int i = 1; i <= N;i++)
    {
        if(in_degree[i] == 0&&!isVis[i])
        {
            que.push(i);
            isVis[i] = true;
        }
    }

    while (!que.empty())
    {
        int n = que.front();
        que.pop();
        cout << n << " ";

        for (int i = 0; i < edges[n].size();i++)
        {
            int j = edges[n][i];
            in_degree[j]--;

            if(!isVis[j]&&in_degree[j] == 0)
            {
                que.push(j);
                isVis[j] = true;
            }
        }
    }
    

    return 0;
}