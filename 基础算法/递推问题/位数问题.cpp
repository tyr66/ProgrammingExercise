#include<iostream>
#include<vector>

using namespace std;

int res[1001][2];

int main()
{
    int N;
    cin >> N;

    res[1][0] = 9;
    res[1][1] = 1;
    res[2][0] = 73;
    res[2][1] = 17;

    for (int i = 3; i <= N;i++)
    {
        res[i][0] = (res[i-1][1] + res[i-1][0] * 9) % 12345;
        res[i][1] = (res[i-1][1] * 9 + res[i-1][0]) % 12345;
    }

    cout << res[N][0]<<endl;

    return 0;
}