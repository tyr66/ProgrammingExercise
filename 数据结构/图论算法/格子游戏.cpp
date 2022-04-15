#include <iostream>

using namespace std;

int map[201][201];
int N;
int get_parent(int i, int j)
{
    if (map[i][j] == i * N + j)
        return map[i][j];

    map[i][j] = get_parent(map[i][j] / N, map[i][j] % N);

    return map[i][j];
}

void Union(int i1, int j1, int i2, int j2)
{
    int par1 = get_parent(i1, j1);
    int par2 = get_parent(i2, j2);

    if (par1 == par2)
        return;

    map[par1 / N][par1 % N] = par2;
}

int main()
{
    int M;
    cin >> N >> M;

    bool flag = false;
    int res;

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
            map[i][j] = i * N + j;
    }

    for (int k = 0; k < M; k++)
    {
        int i, j;
        int i1, j1;
        char c;
        cin >> i >> j >> c;
        i1 = i;
        j1 = j;

        switch (c)
        {
        case 'D':
            i1 = i + 1;
            break;
        case 'R':
            j1 = j + 1;
            break;
        }

        if (flag)
            continue;

        if (get_parent(i, j) == get_parent(i1, j1))
        {
            flag = true;
            res = k + 1;
        }else
            Union(i,j,i1,j1);
    }

    if (flag)
        cout << res << endl;
    else
        cout << "draw\n";
}