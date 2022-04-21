#include <iostream>
#include <vector>
using namespace std;

struct Game
{
    int t;
    int m;

    bool operator<(const Game &g)
    {
        return m > g.m;
    }
    bool operator>(const Game &g)
    {
        return m < g.m;
    }
};
template <typename T>
void quickSort(vector<T> &arr, int lo, int hi)
{
    if (lo >= hi)
        return;

    int i, j, k;
    i = lo + 1;
    j = hi;
    k = lo;

    while (i <= j)
    {
        if (arr[k] < arr[i])
            swap(arr[i], arr[j--]);
        else if (arr[k] > arr[i])
            swap(arr[k++], arr[i++]);
        else
            i++;
    }

    quickSort(arr, lo, k - 1);
    quickSort(arr, i, hi);
}
int order[501];
int main()
{
    vector<Game> games;
    int N, M;
    cin >> M >> N;

    for (int i = 0; i < N; i++)
    {
        int t;
        cin >> t;
        games.push_back({t, 0});
    }

    for (int i = 0; i < N; i++)
    {
        int m;
        cin >> m;
        games[i].m = m;
    }

    quickSort(games, 0, N - 1);
    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        bool flag = false;
        for (int j = games[i].t; j >= 1;j--)
        {
            if(order[j] == 0)
            {
                flag = true;
                order[j] = 1;
                break;
            }
        }

        if(!flag)
            ans += games[i].m;
    }

    cout << M - ans << endl;

    return 0;
}
