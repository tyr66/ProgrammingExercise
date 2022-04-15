#include<iostream>
#include<queue>
#include<vector>
using namespace std;


vector<int> edges[100001];
bool isVis[100001];

int main()
{
    int N, M, S;
    int Step;
    cin >> N >> M >> S >> Step;

    for (int i = 0; i < M;i++)
    {
        int from, to, w;
        cin >> from >> to;

        edges[from].push_back({to});
        edges[to].push_back({from});
    }

    int count = 1, res = 0;
    queue<int> que;
    isVis[S] = true;
    que.push(S);


    while(!que.empty())
    {
        int n = que.front();
        que.pop();

        for (int i = 0; i < edges[n].size();i++)
        {
            int to = edges[n][i];
            
            if(isVis[to])
                continue;

            isVis[to] = true;
            que.push(to);
        }

        if(--count == 0)
        {
            count = que.size();
            res++;
        }
    }

    cout << res + Step << endl;

    return 0;
}