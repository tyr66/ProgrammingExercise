#include<iostream>
#include<queue>
using namespace std;

char mat[1000][1000];
int step[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};
int n, m;

void bfs(int i,int j)
{
    queue<int> que;

    que.push(i);
    que.push(j);
    mat[i][j] = '0';

    while(!que.empty())
    {
        int r = que.front();
        que.pop();
        int c = que.front();
        que.pop();


        for (int k = 0; k < 4;k++)
        {
            int n_r = r + step[k][0];
            int n_c = c + step[k][1];

            if(n_r<0||n_r>=n)
                continue;
            if (n_c < 0||n_c>=m)
                continue;
            if(mat[n_r][n_c]=='0')
                continue;

            que.push(n_r);
            que.push(n_c);
            mat[n_r][n_c] = '0';
        }
    }


}

int main()
{
    int ans = 0;
    cin >> n >> m;
    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            cin >> mat[i][j];
        }
    }

    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < m;j++)
        {
            if(mat[i][j]!='0')
            {
                bfs(i,j);
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}