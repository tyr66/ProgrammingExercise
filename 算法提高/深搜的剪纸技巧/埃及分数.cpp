#include <iostream>
using namespace std;

/**
 * 思路：深搜+可行性剪纸
 * 思路不难，从长度位2开始进行遍历直到找到第一个存在的分解的长度，并从从找到一个尾部最大的答案
 * 难点在于进行可行性剪枝，否则算法的时间复杂度就会过大，当找到第i个单位分数的时候，我们判断当
 * 余下长度全部为该单位分数的时候，是否会比剩下的分数大。当是时则表示可以继续寻找下一个单位分数
 * 否则因为下一个单位分数必然会比当前的小，在这种情况下我们永远也不会成功将当前分数分解成单位分数
 * 所以这种情况下可以直接放弃搜索
 */

long long arr[100000], ans[100000];
long long minTail = 0x3f3f3f3f;

//最大公约数
long long gcd(long long n, long long m)
{
    if (m == 0)
        return n;

    return gcd(m, n % m);
}

// 最小公倍数
// 然后lcm(a,b)=a*b/gcd(a,b)
long long lcm(long long  a, long long b)
{
    if (a < b)
        swap(a, b);
    return a * b / gcd(a, b);
}

bool dfs(long long n, long long m, long long prev, int d,int max_depth)
{
    if (max_depth == d)
    {
        if (n == 0 && prev < minTail)
        {
            minTail = prev;

            for (int i = 0; i<d; i++)
            {
                ans[i] = arr[i];
                //cout << arr[i]<<" ";
            }
            //cout << endl;
        }

        return n == 0;
    }

    if(n == 0)
        return false;

    //前面的尾部比最小的尾部大或者等于
    if (prev >= minTail)
        return false;

    bool res = false;
    long long i = m % n == 0 ? m / n : m / n + 1;
    i = max(prev + 1, i);
    while (i < minTail)
    {
        long long p = lcm(i, m);
        arr[d] = i;
        if(dfs(n * (p / m) - (p / i), p, i, d + 1,max_depth))
        {
            res = true;
        }
        if((max_depth -d)*m<=i*n) //可行性剪枝
            break;
        i++;
    }

    return res;
}

int main()
{
    int n, m;
    cin >> n >> m;

    int d;
    for (d = 2;; d++)
    {
        minTail = 0x3f3f3f3f;
        if (dfs(n, m, 0, 0,d))
        {
            break;
        }
    }

     for (int i = 0; i<d; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}