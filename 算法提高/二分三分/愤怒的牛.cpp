#include <iostream>
using namespace std;

int arr[100000];
int N, C;

void quickSort(int lo, int hi)
{
    if (lo >= hi)
        return;

    int i = lo + 1;
    int k = lo;
    int j = hi;

    while (i <= j)
    {
        if (arr[k] < arr[i])
        {
            swap(arr[i], arr[j--]);
        }
        else if (arr[k] > arr[i])
        {
            swap(arr[k++], arr[i++]);
        }
        else
            i++;
    }

    quickSort(lo, k - 1);
    quickSort(i, hi);
}

bool isValid(int v)
{
    int count = 1;

    int d = arr[0];
    for (int i = 1; i < N; i++)
    {
        if (arr[i] - d >= v)
        {
            count++;
            d = arr[i];
        }
    }

    return count >= C;
}

int main()
{

    int lo = 0;
    int hi;
    cin >> N >> C;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
    }
    quickSort(0, N - 1);

    lo = 0;
    hi = 1000000000+1;

    while(hi - lo>1)
    {
        int mid = (hi+lo)>>1;

        if(isValid(mid))
        {
            lo = mid;
        }else
        {
            hi = mid;
        }
    }

    cout << lo << endl;

    return 0;
}