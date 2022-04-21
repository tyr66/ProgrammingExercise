#include<iostream>
using namespace std;

double f(double x)
{
    /* float res = x - 15;
    res = x * res + 85;
    res = x * res - 255;
    res = x * res + 274;
    res = x * res - 121; */
    return x * x * x * x * x - 15 * x * x * x * x + 85 * x * x * x - 225 * x * x + 274 * x - 121;
}

int main()
{
    double min_v = 1.5f;
    double max_v = 2.4f;

    while(max_v - min_v>=1e-7)
    {
        double mid = (max_v + min_v) / 2;

        if(f(min_v)*f(mid)<=0)
        {
            max_v = mid;
        }else
        {
            min_v = mid;
        }
    }

    max_v += 5e-7;

    printf("%.6lf\n",max_v);
    //cout << f(1.5)<<endl;
    //cout << f(2.4);
    return 0;
}