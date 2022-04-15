#include<iostream>
#include<queue>
using namespace std;

const int N = 10;
int map[N][N];
int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

void bfs(int r,int c)
{
    queue<int> que;
    que.push(r);
    que.push(c);
    map[r][c] = 1;
    int i, j;

    while(!que.empty())
    {
        i = que.front();
        que.pop();
        j = que.front();
        que.pop();

        for (int k = 0; k < 4;k++)
        {
            int n_i = i + step[k][0];
            int n_j = j + step[k][1];

            if(n_i<0||n_i>=N)
                continue;
            if(n_j<0||n_j>=N)
                continue;
            if(map[n_i][n_j] == 1)
                continue;

            que.push(n_i);
            que.push(n_j);
            map[n_i][n_j] = 1;
        }
    }
}

int main()
{

    for (int i = 0; i < N;i++)
    {
        for (int j = 0; j < N;j++)
        {
            cin >> map[i][j];
        }
    }

    for (int j = 0; j < N;j++)
    {
        if (map[0][j] == 0)
        {
            bfs(0,j);
        }
    }

    
    for (int j = 0; j < N;j++)
    {
        if (map[N-1][j] == 0)
        {
            bfs(N-1,j);
        }
    }

    for (int i = 0; i < N;i++)
    {
        if(map[i][0]==0)
        {
            bfs(i,0);
        }
    }

    
    for (int i = 0; i < N;i++)
    {
        if(map[i][N-1]==0)
        {
            bfs(i,N-1);
        }
    }

    int res = 0;

    for (int i = 0; i < N;i++)
    {
        for (int j = 0; j < N;j++)
        {
            if(map[i][j]==0)
                res++;
        }
    }

    cout << res << endl;

    return 0;
}