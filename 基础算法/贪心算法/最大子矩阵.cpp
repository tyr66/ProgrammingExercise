#include<iostream>
#include<vector>

using namespace std;

int matrix[101][101];


int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n;i++)
    {
        for (int j = 1; j <= n;j++)
        {
            cin >> matrix[i][j];

            matrix[i][j] += matrix[i][j-1];
        }
    }

    int ans = 0;
    int res = (-2147483647 - 1);

    for (int i = 0; i <= n - 1;i++)
    {
        for (int j = i + 1; j <= n;j++)
        {
            ans = 0;
            for (int k = 1; k <= n;k++)
            {
                ans += matrix[k][j] - matrix[k][i];
                res = max(res,ans);
                if(ans<0)
                    ans = 0;
            }
        }
    }

    cout << res << endl;

    return 0;
}