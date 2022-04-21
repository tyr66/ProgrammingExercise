#include<iostream>
using namespace std;

int arr[100000];

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

int binarySearch(int lo,int hi,int tar)
{
    while(lo<=hi)
    {
        int mid = (lo+hi)>>1;
        if(arr[mid]>tar)
        {
            hi = mid - 1;
        }else if(arr[mid]<tar)
        {
            lo = mid + 1;
        }else
            return mid;
    }

    return -1;
}

int main()
{
    int N,M;
    cin >> N;

    for (int i = 0; i < N;i++)
    {
        cin >> arr[i];
    }

    cin >> M;

    quickSort(0,N-1);

    for (int i = 0; i < N;i++)
    {
        if(binarySearch(i,N-1,M - arr[i])!=-1)
        {
            cout << arr[i] << " " << M - arr[i] << endl;
            return 0;
        }
    }

    cout << "No\n";
    return 0;
}