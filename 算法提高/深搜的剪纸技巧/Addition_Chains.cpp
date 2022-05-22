#include<iostream>
using namespace std;

/**
 * 思路：深搜+剪枝
 * 对于第i个数字n，n都由其前一个位数字和n之前的某个数字之和组成。既arr[i] = arr[i-1]+arr[j],j = [1,i-1],这类似于一种
 * 贪心策略，假设第i个数组并非由其 arr[i-1]和arr[j]组成，而是由其 arr[j]和arr[k] j = [1,i-2],k= [1,i-2] 那么第i-1位上的
 * 数字就失去了价值，完全可以删除。因此在长度最小的情况下我们知道第i位的数字一定由其i-1为上的数字和[1,i-1]位上的数字组成。
 * 知道了如上的信息，我们就可以从第二位开始来进行组成，不停的进行深搜知道找到目标值并且记录长度最小的情况
 */

int arr[100000],ans[100000];
int N;
int minDepth;

void dfs(int n)
{
    if(n-1>=minDepth)
        return;
    if(n-1>N)
        return;
    if(arr[n-1] >N)
        return;
    if(arr[n-1] == N)
    {
        if(minDepth<=n-1)
            return;

        minDepth = n - 1;
        for (int i = 1; i < n;i++)
            ans[i] = arr[i];
        return;
    }

    for (int i = n - 1; i >= 1;i--)
    {
        arr[n] = arr[n - 1] + arr[i];
        dfs(n+1);
    }
    arr[n] = 0;
}

int main()
{
    arr[1] = 1;
    ans[1] = 1;
    while(scanf("%d",&N))
    {
        if(N == 0)
            break;

        minDepth = 0x3f3f3f3f;
        dfs(2);
        for (int i = 1; i <= minDepth;i++)
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }


    return 0;
}