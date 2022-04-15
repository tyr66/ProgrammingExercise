#include<iostream>
#include<vector>

using namespace std;

int arr[1000001];
int num;

int cal(int k)
{
    if(num>=k)
        return arr[k];

    for (int i = num + 1; i <= k;i++)
    {
        arr[i] = (2*arr[i - 1] + arr[i - 2])%32767;
    }

    num = k;
    return arr[k];
}

int main()
{

    int n;
    cin >> n;

    vector<int> res;
    res.resize(n);

    arr[1] = 1;
    arr[2] = 2;
    num = 2;

    for (int i = 0; i < n;i++)
    {
        cin >> res[i];
    }

    for (int i = 0; i < n;i++)
    {
        res[i] = cal(res[i]);
        cout << res[i] << endl;
    }



    return 0;
}