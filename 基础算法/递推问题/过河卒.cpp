#include<iostream>
#include<vector>

using namespace std;

long long checkboard[21][21];

int main()
{
    int n, m;
    int c_i, c_j;
    cin >> n >> m;
    cin >> c_i >> c_j;

    checkboard[0][0] = 1;

    for (int i = 0; i <= n;i++)
    {
        for (int j = 0; j <= m;j++)
        {
            if(i==c_i&&j==c_j)
                continue;

            int dis_i = abs(c_i-i);
            int dis_j = abs(c_j-j);

            if(dis_i<=2&&dis_j<=2&&(dis_i+dis_j) == 3)
            {
                continue;
            }

            if(i-1>=0)
                checkboard[i][j] += checkboard[i - 1][j];
            if(j-1>=0)
                checkboard[i][j] += checkboard[i][j - 1];
        }
    }

    cout << checkboard[n][m]<<endl;

    return 0;
}