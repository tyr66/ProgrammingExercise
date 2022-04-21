#include<iostream>
using namespace std;

long long mod(long long p,long long q,long long k)
{
    if(q == 0)
        return 1%k;
    if(q ==1)
        return p % k;

    long long m = mod(p,q>>1,k);

    if(q%2 == 0)
        return (m * m) % k;

    return (m * m * (p%k) ) % k;
}

int main()
{
    int p, q, k;
    cin >> p >> q >> k;

    printf("%d^%d mod %d=%d\n",p,q,k,mod(p,q,k));

    return 0;
}