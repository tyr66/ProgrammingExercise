#include<iostream>
using namespace std;

int arr[100009];
int tmp[100009];
int N;

void merge(int lo,int mid,int hi)
{
    int i = lo;
    int j = mid + 1;
    int k = lo;
    while(i<=mid||j<=hi)
    {
        if(i>mid)
            tmp[k++] = arr[j++];
        else if(j>hi)
            tmp[k++] = arr[i++];
        else if(arr[i]>arr[j])
            tmp[k++] = arr[j++];
        else
            tmp[k++] = arr[i++];
    }

    for (int i = lo; i <= hi;i++)
    {
        arr[i] = tmp[i];
    }
}

long long getInverseCount(int lo,int hi)
{
    if(lo >=hi)
        return 0;

    int mid = (lo+hi)/2;
    long long left = getInverseCount(lo,mid);
    long long right = getInverseCount(mid+1,hi);
    long long count = 0;

    for (int i = lo,j = mid+1; i <= mid;i++)
    {
        for (; arr[i] > arr[j]&&j<=hi;j++)
            ;

        count += j - mid - 1;
    }

    merge(lo,mid,hi);

    return left + right + count;
}

int main()
{
    cin >> N;

    for (int i = 0; i < N;i++)
        cin >> arr[i];

    printf("%lld\n",getInverseCount(0,N-1));

    return 0;
}