#include<iostream>
#include<queue>

using namespace std;

int W, H, D;

char mat[100][100][100];
int s_i, s_j, s_k;
int t_i, t_j, t_k;
int step[6][3] = {{1,0,0},{-1,0,0},{0,1,0},{0,-1,0},{0,0,1},{0,0,-1}};

int bfs()
{
    int ans = 0;
    int res = 0;
    int k, i, j;
    bool flag = false;
    queue<int> que;
    que.push(s_k);
    que.push(s_i);
    que.push(s_j);

    mat[s_k][s_i][s_j] = '#';
    ans = 3;

    while(!que.empty()&&!flag)
    {
        k = que.front();
        que.pop();
        i = que.front();
        que.pop();
        j = que.front();
        que.pop();

        if(i == t_i&&j == t_j&&k == t_k)
        {
            flag = true;
            break;
        }

        for (int n = 0; n < 6;n++)
        {
            int n_k = k + step[n][0];
            int n_i = i + step[n][1];
            int n_j = j + step[n][2];

            if(n_k<0||n_k>=D)
                continue;
            if(n_i<0||n_i>=H)
                continue;
            if(n_j<0||n_j>=W)
                continue;
            
            if(mat[n_k][n_i][n_j] == '#')
                continue;

            mat[n_k][n_i][n_j] = '#';
            que.push(n_k);
            que.push(n_i);
            que.push(n_j);
        }

        ans-=3;
        if(ans == 0)
        {
            ans = que.size();
            res++;
        }
    }

    return flag?res:-1;
}

int main()
{
    while(cin >> D >> H >> W)
    {
        if(D==0&&W==0&&H==0)
            break;

        for (int d = 0; d < D;d++)
        {
            for (int h = 0; h < H;h++)
            {
                for (int w = 0; w < W;w++)
                {
                    cin >> mat[d][h][w];

                    if(mat[d][h][w] == 'S')
                    {
                        s_i = h;
                        s_j = w;
                        s_k = d;
                    }
                    
                    if(mat[d][h][w] == 'E')
                    {
                        t_i = h;
                        t_j = w;
                        t_k = d;
                    }
                }
            }
        }

        int ans = bfs();

        if(ans>0)
        {
            printf("Escaped in %d minute(s).\n",ans);
        }else
        {
            printf("Trapped!\n");
        }
    }

    return 0;
}