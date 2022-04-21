#include <iostream>
using namespace std;

int arr[1000001];
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

int find_rightSide(int lo, int hi, int tar)
{
    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;

        if (arr[mid] <= tar)
            lo = mid + 1;
        else
            hi = mid - 1;
    }

    //在边界要判断是否和tar相等
    if(lo==N)
        return arr[lo-1] == tar?N-1:-1;

    //还要判断一下左边的值是否和tar相等
    if(lo>0&&arr[lo-1] == tar)
        return lo - 1;

    return max(lo,0);
}

int find_leftSide(int lo, int hi, int tar)
{
    while (lo <= hi)
    {
        int mid = (lo + hi) >> 1;

        if (arr[mid] >= tar)
            hi = mid - 1;
        else
            lo = mid + 1;
    }

    if(hi == -1)
        return arr[hi+1] == tar?hi+1:-1;

    if(hi<N-1&&arr[hi+1] == tar)
        return hi + 1;
    return min(hi,N-1);
}

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    quickSort(0, N - 1);

    int M;
    cin >> M;

    while (M > 0)
    {
        int tar;
        cin >> tar;
        int rightSide = find_rightSide(0, N - 1,tar);
        int leftSide = find_leftSide(0,N-1,tar);

        //cout << leftSide << "  " << rightSide << endl;

        if(rightSide ==-1)
            cout << arr[leftSide]<<endl;
        else if(leftSide ==-1)
            cout << arr[rightSide] << endl;
        else
        {
            if(abs(tar - arr[leftSide])>abs(tar - arr[rightSide]))
            {
                cout << arr[rightSide] << endl;
            }else 
            {
                cout << arr[leftSide] << endl;
            }
        }    


        M--;
    }

    return 0;
}