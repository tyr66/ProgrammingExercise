#include<iostream>
#include<string>

using namespace std;

int res[40000];

int main()
{
    int N;
    int idx = 1;//位数
    cin >> N;

    res[0] = 1;

    for (int n = 2; n <= N;n++)
    {
        int up = 0;

        for (int i = 0; i < idx;i++)
        {
            int val = res[i] * n + up;
            res[i] = val % 10;
            up = val / 10;
        }

        while(up!=0)
        {
            res[idx++] = up % 10;
            up /= 10;
        }
    }

    for (int i = idx-1; i >=0;i--)
    {
        cout << res[i];
    }
    cout << endl;

    return 0;
}