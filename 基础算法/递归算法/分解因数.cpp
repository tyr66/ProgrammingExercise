#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

int decomposeFactor(int n,int num)
{
    if(n == 1||num == 1)
        {
            return 1;
        }

    int res = 0;

    for (int i = num; i <= n;i++)
    {
        if(n%i == 0)
        {
            res+=decomposeFactor(n/i,i);
        }
    }

    return res;
}


int DecomposeFactor(int n)
{
    int res= 0;
    for (int i = 1; i < n;i++)
    if(n%i==0)
        res+=decomposeFactor(n/i, i);

    return res;
}

int main()
{
    int n;
    vector<int> arr;
    cin >> n;

    arr.resize(n);
    for (int i = 0; i < n;i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << DecomposeFactor(arr[i]) << endl;
    }

    return 0;
}