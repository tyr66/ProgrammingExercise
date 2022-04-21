#include <iostream>
using namespace std;

int arr[10000];
int N;

int main()
{
    cin >> N;

    for (int i = 0; i < N; i++)
        cin >> arr[i];

    int count = 0;

    for (int i = 0; i < N;i++)
    {
        for (int j = 0; j < N - i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);
                count++;
            }
        }
    }

        cout << count << endl;
    return 0;
}