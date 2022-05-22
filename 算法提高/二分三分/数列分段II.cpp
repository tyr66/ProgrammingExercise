#include <iostream>
using namespace std;

int arr[1000000];
int N, M;

bool isValid(long long v)
{
    int count = 0;
    long long sum = 0;
    for (int i = 0; i < N; i++)
    {
        if (v < arr[i])
            return false;

        sum += arr[i];

        if (sum > v)
        {
            count++;
            sum = arr[i];
        }
    }

    return count + 1 <= M;
}

int main()
{
    long long lo = 0x3f3f3f3f;
    long long hi = 0;
    cin >> N >> M;
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        lo = min((int)lo,arr[i]);
        hi += arr[i];
    }

    while(hi-lo>=1)
    {
        long long mid = (lo+hi)>>1;

        if(isValid(mid))
        {
            hi = mid;
        }else
            lo = mid+1;
    }

    cout << lo << endl;

    return 0;
}