#include<iostream>

using namespace std;

int upDp[100];
int downDp[100];
int arr[100];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n;i++)
        cin >> arr[i];

    for (int i = 0;i<n;i++)
    {
        upDp[i] = 1;

        for (int j = 0; j < i;j++)
        {
            if(arr[i]>arr[j])
            {
                upDp[i] = max(upDp[j]+1,upDp[i]);
            }
        }
    }

    for (int i = n - 1; i >= 0;i--)
    {
        downDp[i] = 1;
        for (int j = i + 1; j < n;j++)
        {
            if(arr[i]>arr[j])
            {
                downDp[i] = max(downDp[j]+1,downDp[i]);
            }
        }
    }

    int res = 2147483647;

    for (int i = 0; i < n;i++)
    {
        res = min(n - upDp[i] - downDp[i]+1,res);
    }

    cout << res << endl;

    return 0;
}