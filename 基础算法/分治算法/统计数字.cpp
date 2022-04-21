#include <iostream>
using namespace std;

/**
 * 思路：二分
 * 查找重复的个数使用二分查找，否则可能超时。因为最多有200000个数字，但是不重复的最多有10000个也就是如果在一个已经排好序的数组中查找某个
 * 数的重复次数，最多要检查190000次。
 */

int arr[200001];
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

int find_rightSide(int tar, int lo, int hi)
{
    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;

        if (arr[mid] <= tar)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    return hi;
}

int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> arr[i];

    quickSort(0, N - 1);

    /* for (int i = 0; i < N;i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; */

    for (int i = 0; i < N;)
    {
        int rightSide = find_rightSide(arr[i], i, N - 1);
        cout << arr[i] << " " << rightSide - i+1<<endl;
        i = rightSide + 1;
    }

    return 0;
}