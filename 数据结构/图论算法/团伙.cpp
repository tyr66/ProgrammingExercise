#include <iostream>
using namespace std;
int N, M;

int parent[1001];
int enemy[1001][1001];

int get_parent(int n)
{
    if (parent[n] == n)
        return n;

     parent[n] = get_parent(parent[n]);
     return parent[n];
}

void Union(int i, int j)
{
    int i_par = get_parent(i);
    int j_par = get_parent(j);

    if (i_par == j_par)
        return;

    parent[i_par] = j_par;
}

int main()
{
    cin >> N >> M;

    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int k = 0; k < M; k++)
    {
        int tp, from, to;
        cin >> tp >> from >> to;

        if (tp == 0)
        {
            Union(from, to);
            continue;
        }

        enemy[from][to] = 1;
        enemy[to][from] = 1;

        for (int i = 1; i <= N; i++)
        {
            if (enemy[to][i])
            {
                Union(from, i);
            }
            if (enemy[from][i])
            {
                Union(to, i);
            }
        }
    }

    int res = 0;

    for (int i = 1; i <= N; i++)
    {
        if (parent[i] == i)
            res++;
       // cout << parent[i] << " ";
    }

    cout << res << endl;
}