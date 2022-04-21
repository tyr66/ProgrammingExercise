#include <iostream>
using namespace std;

int arr[100001];

int main()
{
    int N, M;
    cin >> N >> M;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int sum = 0;
    int ans = 1;
    for (int i = 0; i < N; i++)
    {
        sum += arr[i];

        if(sum>M)
        {
            sum = arr[i];
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}