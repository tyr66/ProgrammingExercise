#include <iostream>
#include <math.h>
using namespace std;

/**
 * 思路：非常棒的一道题，思路使用了动态规划和二分查找
 * 我们可以比较容易得出可能答案的最大值和最小值，即为序列中最大元素和最小元素。当数组中的元素全为最大值的时候，答案为最大值，当数组中的元素全为最小值的时候，
 * 答案为最小值二分法的关键在于判断“一个可能的解跟正确答案相比是大了还是小了”。网上给的方法是：如果要判断val这个解，那就让序列里所有元素的值都减去val。
 * 然后在此基础上试图寻找一段连续的区间，该区间的长度大于F，并且该段区间的和最大。可见，问题一下转化成求以第j数字数字结尾长度至少为L的和的最大值，而不是数字的平均值，
 * 问题变得明朗了。而以第j个元素结尾的连续和可以通过 sum[i,j] -v*n_ij 来快速求解。 寻找这种区间的算法是一个很简单的动态规划，复杂度为O(N)。
 * 用 f[a, b] 表示在区间 [a, b] 中，所有子区间的最大值。那么
    当 b - a = F 时，f[a, b] 为序列中对应的和。
    当 b - a > F 时，f[a, b] = max{ f[a, b - 1] + arr[b], f[b - f + 1, b] }
 * 一个容易让人误解的点在于以第j个元素长度至少为L的最大连续和f[i,j]是否对应于以第j个元素结尾长度至少为L的子序列的最大期望值呢？
 答案是否定的，我们来看 sum[i,j] -v*n_ij = d ，其中的d即为f[i,j]的值那么此时的期望值为：sum[i,j]/n_ij = d/n_ij +v 
 可以发现当 d/n_ij 的值最大时我们才可以求出以第j个元素结尾长度至少为L的子序列的最大期望值，d值此时确实是可以求得的最大值，但问题是
 对应的 d/n_ij 此时并不一定能取得最大值。因此可以发现最大的连续和的值和题目需要求的最大期望值并没有对应关系。 

 参考：http://www.cppblog.com/varg-vikernes/archive/2010/03/02/108737.aspx
 */

double arr[100001];
double sum[100001];
int N, L;
const int MAXINT = 0x7fffffff;
#define ex 1e-4

bool isValid(double v)
{
    double prev = sum[L - 1] - v * (L - 1);
    double cur;
    double max_v;
    for (int i = L; i <= N; i++)
    {
        cur = (sum[i] - sum[i - L]) - v * L;
        prev = prev + arr[i] - v;
        max_v = max(cur, prev);

        if (max_v > -ex)
            return true;

        prev = max_v;
    }

    return false;
}

int main()
{
    cin >> N >> L;

    double lo = 1e50;
    double hi = 0;

    for (int i = 1; i <= N; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];

        lo = min(lo, arr[i]);
        hi = max(hi, arr[i]);
    }

    while (hi - lo >= ex)
    {
        double mid = (lo + hi) / 2;

        if (isValid(mid))
        {
            lo = mid;
        }
        else

        {
            hi = mid;
        }
    }


    cout << (int)(hi * 1000) << endl;

    return 0;
}