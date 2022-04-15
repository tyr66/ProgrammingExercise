#include<iostream>
#include<vector>

using namespace std;

long long res[31][31];

int main()
{

    int n, k;
    cin >> n >> k;

    for (int i = 1; i <= n;i++)
        res[i][i] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (i - 1 >= j)
            {
                res[i][j] = res[i - 1][j] * j + res[i - 1][j - 1];
            }
        }
    }

    cout << res[n][k]<<endl;

    return 0;
}