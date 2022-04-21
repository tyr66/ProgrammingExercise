#include<iostream>
#include<math.h>
using namespace std;

/**
 * 思路：二分查找
 * 这道题关键在于精度，我们可以选择使用double 类型或者是将数全部转换成整数来进行处理。这两种方法的不同之处在于
 * 他们的计算精度是不同的，时刻要注意将2.00赋值给一个double类型的变量，它实际的存储数值可能为1.999999997，因此
 * 使用double类型来解决问题时存在精度缺失的问题，因此使用整数类型比使用double类型来处理问题的精度会更高。该题使用
 * double类型来进行处理最多能ac 80%的测试用例。
 */

long long rope[10000];
int N,M;

bool canCut(long long len)
{
    int count = 0;
    for (int i = 0; i < N; i++)
        count += rope[i] / len;
    
    return count >= M;
}

int main()
{
    cin >> N >> M;
    long long  lo = 0;
    long long hi = 0;
    for (int i = 0; i < N;i++)
    {
        double len;
        cin >> len;
        rope[i] = (long long)(len * 100);

        hi = max(hi,rope[i]);
    }

    hi += 1;//为了将hi也有可能取到

    while(hi - lo >1)
    {
        long long mid = (hi+lo)/2;

        if(canCut(mid))
        {
            lo = mid;
        }else
            hi = mid;
        
    }

    printf("%.2lf\n",lo/100.0);
    return 0;
}