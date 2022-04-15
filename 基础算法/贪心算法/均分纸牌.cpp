#include<iostream>
#include<vector>

using namespace std;

int arr[101];

int main()
{
    int n;
    cin >> n;
    int sum = 0;

    for (int i = 1; i <= n;i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    int count = 0;
    int average = sum / n;
    

    for (int i = 1; i <= n;i++)
    {
        arr[i] -= average;
        arr[i] += arr[i-1];

        if(arr[i]!=0)
        {
            count++;
        }
    }

    cout << count<<endl;

    return 0;
}