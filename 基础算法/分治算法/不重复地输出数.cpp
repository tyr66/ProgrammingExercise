#include<iostream>
using namespace std;

int arr[100000];
    int N;

void quickSort(int lo, int hi)
{
    if (lo >= hi)
        return;

    int i = lo + 1;
    int j = hi;
    int k = lo;

    while (i <= j)
    {
        if (arr[k] > arr[i])
        {
            swap(arr[i++], arr[k++]);
        }
        else if (arr[k] < arr[i])
        {
            swap(arr[i], arr[j--]);
        }
        else
        {
            i++;
        }
    }

    quickSort(lo, k - 1);
    quickSort(i, hi);
}

int findRightSide(int lo,int hi,int tar)
{
    while(lo<=hi)
    {
        int mid = (lo+hi)>>1;

        if(arr[mid]<=tar)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    hi = max(hi,0);
    if(hi<N&&arr[hi] == tar)
        return hi;

    return -1;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N;i++)
        cin >> arr[i];

    quickSort(0,N-1);

    for (int i = 0; i < N;i++)
    {
        cout << arr[i]<<" ";
        i = findRightSide(i,N-1,arr[i]);
    }

        return 0;
}