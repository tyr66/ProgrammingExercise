#include <iostream>
using namespace std;

/**
 * 思路：二分查找
 * 贪心算法不知可不可行，使用二分查找的关键点在于如何判断一个数是否合法
 */

int N, M, L;
int dist[500100];

//判断一个数是否合法
bool isValid(int v)
{
    int count = 0;
    int d = 0;
    for (int i = 1; i <= N;i++)
    {
        if(dist[i] - d<v)
            count++;
        else
            d = dist[i];
    }

    if(dist[N+1] - d<v)
        count++;

    return count <= M;
}

int main()
{
    cin >> L >> N >> M;

    for (int i = 1; i <= N; i++)
    {
        cin >> dist[i];
    }

    dist[N + 1] = L;

    int lo = 0;
    int hi = L + 1;

    while (hi - lo > 1)
    {
        int mid = (lo + hi) >> 1;

        if (isValid(mid))
        {
            lo = mid;
        }
        else
        {
            hi = mid;
        }
    }

    cout << lo << endl;

    return 0;
}