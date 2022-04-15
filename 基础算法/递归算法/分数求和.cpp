#include<iostream>
#include<vector>

using namespace std;

int divisor[10];//除数
int dividend[10];//被除数

int res_dividend;
int res_divisor;

// 最大公因数
int gcd(int n,int m)
{
    if(m == 0)
        return n;

    return gcd(m,n%m);
}

// 最小公倍数
// 然后lcm(a,b)=a*b/gcd(a,b)
int lcm(int a,int b)
{
    if(a<b)
        swap(a,b);
    return a*b/gcd(a,b);
}

void sum(int n)
{
    if(n == 1)
    {
        cin >> res_dividend;
        getchar();
        cin >> res_divisor;
        //printf("%d/%d\n",res_dividend,res_divisor);
        
        return;
    }

    int dd, dr;
    cin >> dd;
    getchar();
    cin >> dr;

    sum(n-1);

    int n_lcm = lcm(dr,res_divisor);
    res_dividend = dd * (n_lcm/dr) + res_dividend * (n_lcm/res_divisor);
    res_divisor = n_lcm;
}

int main()
{

    int n;
    cin >> n;

    sum(n);

    int n_gcd = gcd(res_dividend,res_divisor);
    res_dividend /= n_gcd;
    res_divisor /= n_gcd;

    printf("%d/%d",res_dividend,res_divisor);

    return 0;
}