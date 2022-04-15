#include<iostream>
#include<vector>
#include<queue>

using namespace std;

char map[20][20];
bool letterHash[26];
int r, c;
int step[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

int dfs(int i,int j)
{
    letterHash[map[i][j] - 'A'] = true;
    int res = 0;
    for (int n = 0; n < 4;n++)
    {
        int ii = step[n][0]+i;
        int jj = step[n][1]+j;

        if(ii<0||ii>=r)
            continue;
        if(jj<0||jj>=c)
            continue;

        if(letterHash[map[ii][jj] - 'A'])
            continue;
 

        res = max(res, dfs(ii, jj));

        letterHash[map[ii][jj] - 'A'] = false;
    }

    return 1+res;
}

int main()
{
    cin >> r >> c;

    for (int i = 0; i < r;i++)
    {
        for (int j = 0; j < c;j++)
        {
            cin >> map[i][j];
        }
    }


    cout << dfs(0,0);

    return 0;
}