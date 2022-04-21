#include <iostream>
using namespace std;

long long arr[100000];
int N, M;

bool isFit(long long value)
{
    long long min_group = 0;
    long long sum = 0;

    for (int i = 0; i < N; i++)
    {
        if (value < arr[i])
            return false; //表示该值无法进行分组
        if (sum + arr[i] <= value)
        {
            sum += arr[i];
        }
        else
        {
            min_group++;
            sum = arr[i];
        }
    }

    min_group++;

    return min_group <= M;
}

int main()
{
    cin >> N >> M;
    long long sum = 0;
    long long lo = 0;
    long long hi = sum;

    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        lo = max(arr[i], lo);
    }

    hi = sum + 1;

    while (hi - lo >= 1)
    {
        long long mid = (hi + lo) >> 1;

        if (isFit(mid))
        {
            hi = mid;
        }
        else
        {
            lo = mid+1;
        }
    }

    
    cout << lo << endl;
    
    return 0;
}