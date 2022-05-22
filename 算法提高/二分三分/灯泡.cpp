#include<iostream>
using namespace std;

/**
 * 思路：三分法求极值
 * 本题的关键点在于根据三角形的相似原理，求出当墙上有影子以及墙上没有影子时的影子计算公式，并且能看出
 * 求出的函数具有单调性，并且函数图像为一个凸型或者是凹形，才可使用三分来寻找极值点
 * 
 * 方程推导：https://my.oschina.net/u/4354994/blog/3418469
 */


double H, h, D;

double f(double d)
{
    if(d>h*D/H)
        return d+((D-d)* H/(H-h))-D;//墙上没有影子的时候
    return H + D * (H - h)/(d-D)+d;//墙上有影子的时候
}

int main()
{
    int T;
    cin >> T;

    while(T>0)
    {
        cin >> H >> h >> D;
        double lmid;
        double rmid;
        double left = 0;
        double right = D;

        while(right - left>1e-11)
        {
            lmid = left + (right -left)/3;
            rmid = right - (right -left)/3;

            if(f(lmid)>f(rmid))
            {
                right = rmid;
            }else{
                left = lmid;
            }
        }

        printf("%.3lf\n",f(right));

        T--;
    }

    return 0;
}