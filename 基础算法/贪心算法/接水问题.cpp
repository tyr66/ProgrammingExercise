#include<iostream>
#include<vector>
using namespace std;

int main()
{
    int n, k;
    vector<int> arr;
    cin >> n >> k;
    arr.resize(n);

    for (int i = 0; i < n;i++)
    {
        cin >> arr[i];
    }

    int minIdx = 0;
    for (int i = k; i < n;i++)
    {
        minIdx = 0;
        for (int j = 0; j < k;j++)
        {
            if(arr[j]<arr[minIdx])
            {
                minIdx = j;
            }
        }

        arr[minIdx] += arr[i];
    }

    int maxIdx = 0;
    for (int i = 0; i < k;i++)
    {
        if(arr[i]>arr[maxIdx])
            maxIdx = i;
    }

    cout << arr[maxIdx]<<endl;

    return 0;
}