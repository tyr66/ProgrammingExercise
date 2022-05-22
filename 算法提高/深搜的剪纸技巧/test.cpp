#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define N 105

int n, ans, sum, stick[N], vis[N];
int cmp(const int &a, const int &b)
{
    return a > b;
}
bool dfs(int cnt, int pos, int sum)
{
    if (cnt == n)
        return true;
    for (int i = pos; i < n; i++)
    {
        if (vis[i])
            continue;
        if (sum + stick[i] < ans)
        {
            vis[i] = 1;
            if (dfs(cnt + 1, i + 1, sum + stick[i]))
                return true;
            vis[i] = 0;
            while (stick[i] == stick[i + 1] && i + 1 < n)
            {
                i++;
            }
        }
        else if (sum + stick[i] == ans)
        {
            vis[i] = 1;
            if (dfs(cnt + 1, 0, 0))
                return true;
            vis[i] = 0;
            return false;
        }

        if (sum == 0)
            return false;
    }
    return false;
}

int main()
{

    int len = 0;
    cin >> len;
    int lo = 0, hi = 0;
    for (int i = 0; i < len; i++)
    {
        cin >> stick[n];
        if (stick[n] > 50)
            continue;
        lo = max(lo, stick[n]);
        sum += stick[n];
        n++;
    }
    sort(stick, stick + n, cmp);

    // Handle.
    for (int i = n; i > 0; --i)
    {
        if (sum % i == 0 && (sum / i) >= stick[0])
        {
            ans = sum / i;
            memset(vis, 0, sizeof(vis));

            if (dfs(0, 0, 0))
            {
                printf("%d\n", ans);
                break;
            }
        }
    }

    return 0;
}
