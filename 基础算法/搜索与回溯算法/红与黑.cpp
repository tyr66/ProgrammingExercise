#include<iostream>
#include<vector>

using namespace std;

char map[20][20];
int W, H;
int st_i, st_j;
int step[4][2] = {{1,0},{-1,0},{0,-1},{0,1}};

int dfs(int i,int j)
{
    int res = 1;

    map[i][j] = '#';

    for (int k = 0; k < 4;k++)
    {
        int n_i = step[k][0]+i;
        int n_j = step[k][1]+j;

        if(n_i<0||n_i>=H)
            continue;
        if(n_j<0||n_j>=W)
            continue;
        if(map[n_i][n_j]=='#')
            continue;

        res += dfs(n_i,n_j);
    }

    return res;
}

int main()
{
    while(true)
    {
        cin >> W >> H;

        if(W ==0&&H ==0)
            break;

        for (int i = 0; i < H;i++)
        {
            for (int j = 0; j < W;j++)
            {
                cin >> map[i][j];

                if(map[i][j] == '@')
                {
                    st_i = i;
                    st_j = j;
                }
            }
        }

        cout << dfs(st_i,st_j)<<endl;

    }
    return 0;
}