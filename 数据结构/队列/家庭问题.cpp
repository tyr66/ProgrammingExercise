#include<iostream>
#include<queue>
using namespace std;

bool mark_node[101];
int from[10001];
int to[10001];
int N, K;

int bfs(int n)
{
    if(n>N)
        return 0;

    mark_node[n] = true;
    queue<int> que;
    int count = 0;
    que.push(n);

    while(!que.empty())
    {
        int k = que.front();
        que.pop();

        count++;

        for (int i = 1; i <= K;i++)
        {
            if(from[i] != k&&to[i]!=k)
                continue;
            
            if(mark_node[from[i]]&&mark_node[to[i]])
                continue;
            
            if(!mark_node[from[i]])
            {
                mark_node[from[i]] = true;
                que.push(from[i]);
            }else if(!mark_node[to[i]])
            {
                mark_node[to[i]] = true;
                que.push(to[i]);
            }


        }
    }

    return count;
}

int main()
{
    cin >> N >> K;

    for (int i = 1; i <= K;i++)
        cin >> from[i]>>to[i];

    int count = 0;
    int maxNums = 0;
    for (int i = 1; i <= N;i++)
    {
        if(!mark_node[i])
        {
            count++;
            maxNums = max(bfs(i),maxNums);
        }
    }

    cout << count << " "
         << maxNums << endl;

    return 0;
}