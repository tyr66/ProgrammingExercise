#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main()
{
    int N;
    int res = 0;
    vector<int> arr;

    cin >> N;
    arr.resize(N);
    for (int i = 0; i < N;i++)
        cin >> arr[i];

    for (int i = 0; i < N;i++)
    {
        for (int j = 1; j < N-i;j++)
        {
            if(arr[j-1]>arr[j])
            {
                swap(arr[j-1],arr[j]);
                res++;
            }
        }
    }

    cout << res << endl;

    return 0;
}