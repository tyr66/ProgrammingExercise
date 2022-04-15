#include<iostream>

using namespace std;

int upDp[1000];
int downDp[1000];
int arr[1000];

int main()
{
    int N;
    cin >> N;

    for (int i = 0; i < N;i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < N;i++)
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

    for (int i = N - 1; i >= 0;i--)
    {
        downDp[i] = 1;
        for (int j = i + 1; j < N;j++)
        {
            if(arr[i]>arr[j])
            {
                downDp[i] = max(downDp[j]+1,downDp[i]);
            }
        }
    }

    int res = 0;

    for (int i = 0; i < N;i++)
    {
        res = max(res,upDp[i]+downDp[i]-1);
    }

    cout << res << endl;
    return 0;
}