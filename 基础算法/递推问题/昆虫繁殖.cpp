#include<iostream>
#include<vector>

using namespace std;

long long a[51],b[51];

int main()
{
    int x, y,z;
    int res = 1;
    cin >> x >> y >> z;

    a[1] = 1;

    for (int i = 0; i <= z + 1;i++)
        a[i] = 1;

    for (int i = x + 1; i <= z + 1; i++)
    {
        b[i] = a[i - x] * y;
        a[i] = a[i - 1] + b[i - 2];
    }

    printf("%lld\n",a[z+1]);

    return 0;
}