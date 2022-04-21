#include<iostream>
#include<algorithm>
using namespace std;

/**
 * 思路：二分法
 * 从-100开始每隔1检查该区间内是否存在一个解，因为解之间的距离至少为1.因为每隔区间最多存在一个解，不存在一个区间内
 * 有多个解的情况。如果确定某个区间内一定存在一个解，那么在这个区间里进行二分查找，直到解精确到小数点后两位。
 * 思考：直接在-100到100进行二分查找，直到找到3个解这个方法可不可行，答案是可行的。但是这个解决方案解的精度无法精确到小数点后两位
 * 因此无法通过所有的测试
 */

float solve[3];
int N;
float threshold = 1e-2;
float a, b, c, d;

float cal(float v)
{
    return a * v * v * v + b * v * v + c * v + d;
}

int main()
{
    cin >> a >> b >> c >> d;

    for (float x = -100; x <= 100;x+=1.0f)
    {
        float xx = x + 1.0f;

        if(cal(x) ==0)
            printf("%.2lf ",x);
        
        if(cal(x)*cal(xx)<0)
        {
            while((xx -x)>=0.001f)
            {
                float mid = (xx + x) / 2;
                if(cal(mid)*cal(x)<=0)
                {
                    xx = mid;
                }else 
                {
                    x = mid;
                }
            }

            printf("%.2lf ",x);
        }
    }

        return 0;
}