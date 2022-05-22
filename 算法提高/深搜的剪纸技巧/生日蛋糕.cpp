#include <iostream>
#include <vector>
#include<math.h>

/**
 * 思路：深搜+剪枝
 * 详细阅读代码
 */

using namespace std;
#define MAXINT 0x3f3f3f3f
int N, M;
int min_sumv[21],min_sums[21];
int res = MAXINT;

//从底层往上
void cal_surfacearea(int n, int m, int area, int prevR, int prevH)
{
    if(m == 0)
    {
        if(n ==N)
            res = min(res,area);

        return;
    }

    //剩下的体积不足
    if(N-n<0)
        return;
    //往后能获得的最小体积加上当前获得的体积比目标体积大就返回
    if(n+min_sumv[m-1]>N)
        return;
    //当前获得的表面积加上，往后能获得的最小表面积(该表面积有可能取得)比当前res小就返回
    if(area+min_sums[m-1]>res)
        return;
    //当前获得的表面积加上，往后能获得的最小表面积(实际该体积不可能取得,r取最大表面积最小)都比res大就返回
    if(2*(N-n)/prevR+area>=res)
        return;

    for (int r = prevR - 1; r >= m;r--)
    {
        for (int h = prevH - 1; h >= m;h--)
        {
            int s = 2 * r * h;
            int v = r * r * h;

            if(m == M)
            {
                area = r * r;//每一层的上表面之和为最底层的上表面的面积，好巧妙阿！！！！
            }

            cal_surfacearea(n+v,m-1,area+s,r,h);
        }
    }
}



int main()
{
    cin >> N >> M;

    //从顶层往下计算
    for (int i = 1;i<=M;i++)
    {
        min_sums[i] = min_sums[i - 1] + 2 * i * i;
        min_sumv[i] = min_sumv[i - 1] + i * i * i;
    }

    int maxR = sqrt((N -min_sumv[M-1])/M)+1;
    int maxH = (N - min_sumv[M - 1]) / (M*M)+1;

    cal_surfacearea(0,M,0,maxR,maxH);

    if (res == MAXINT)
        res = 0;

    cout << res << endl;

    return 0;
}