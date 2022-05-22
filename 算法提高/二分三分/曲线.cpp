#include<iostream>
using namespace std;

/**
 * 思路：三分法
 * 二分法相信，它最基本的应用是求一个单调函数的零点。三分法是二分法的变种，他最基本的用途是求单峰函数的极值点
 * 在该题中因为a>=0,所以方程f 要么是一个一次方程，要么是一个a>=0的二次方程(开口向上)，因此可以得出方程S一定
 * 是单调的，再仔细的思考可以发现它一定是一个凸性或凹形函数，因此可以使用三分算法来求出极值
 */

#define INF 0x3f3f3f3f
int N;
double a[10000],b[10000],c[10000];

double S(double x)
{
    double maxn = -INF;
    for (int i = 0; i < N;i++)
    {
        maxn = max(maxn,a[i]*x*x+b[i]*x+c[i]);
    }

    return maxn;
}

int main()
{
    int T;
    cin >> T;

    while(T>0)
    {
        cin >> N;
        for (int i = 0; i < N; i++)
            cin >> a[i] >> b[i] >> c[i];

        double lmid , rmid;
        double left = 0;
        double right = 1000;
        while(right - left>=1e-11)
        {
            lmid = left + (right - left)/3;
            rmid = right - (right - left)/3;

            if(S(lmid)>S(rmid))
            {
                left = lmid;
            }else{
                right = rmid;
            }
        }

        printf("%.4lf\n",S(left));

        T--;
    }

    return 0;
}