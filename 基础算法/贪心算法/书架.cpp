#include<iostream>
#include<algorithm>
using namespace std;

int cows[20000];

int main()
{
    int n,B;
    cin >> n>>B;

    for (int i = 0; i < n;i++)
    {
        cin >> cows[i];
    }

    sort(cows,cows+n);

    int ans = 0;
    for (int i = n - 1; i >= 0 && B > 0;i--)
    {
        B -= cows[i];
        ans++;
    }

    cout << ans << endl;

    return 0;
}