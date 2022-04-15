#include<iostream>
#include<queue>
using namespace std;

int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
int map[101][101];

void bfs(int r,int c,int n,int m)
{
    queue<int> que;
    que.push(r);
    que.push(c);
    map[r][c] = 0;

    while(!que.empty())
    {
        int i = que.front();
        que.pop();
        int j = que.front();
        que.pop();

        for (int k = 0; k < 4;k++)
        {
            int n_i = i + step[k][0];
            int n_j = j + step[k][1];

            if(n_i<0||n_i>=n)
                continue;
            if(n_j<0||n_j>=m)
                continue;
            if(map[n_i][n_j] == 0)
                continue;

            map[n_i][n_j] = 0;
            que.push(n_i);
            que.push(n_j);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    int count = 0;

    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            cin>>map[i][j];
        }
    }

    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            if(map[i][j] == 1)
            {
                bfs(i,j,n,m);
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}