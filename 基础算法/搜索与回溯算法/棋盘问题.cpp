#include<iostream>
#include<vector>

using namespace std;

char checkboard[8][8];
bool colHash[8];
int n, k;

int dfs(int r,int k)
{
    if(k == 0)
        return 1;
    if(r>=n)
        return 0;

    int res = 0;

    for (int i = r; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            if(checkboard[i][j] == '#'&&!colHash[j])
            {
                colHash[j] = true;
                res += dfs(i+1,k-1);
                colHash[j] = false;
            }
        }
    }

    return res;
}

int main()
{
    while(true)
    {
        cin >> n >> k;

        if(n==-1&&k==-1)
            break;

        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j < n;j++)
            {
                cin >> checkboard[i][j];
            }
        }

        cout << dfs(0,k)<<endl;
    }


    return 0;
}