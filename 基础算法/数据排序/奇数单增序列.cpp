#include<iostream>
#include<vector>

using namespace std;



void quickSort(vector<int>&arr,int lo,int hi)
{
    if(lo>=hi)
        return;

    int k = lo,i = lo+1,j = hi;

    while(i<=j)
    {
        if(arr[k]>arr[i])
            swap(arr[k++],arr[i++]);
        else if(arr[k]<arr[i])
            swap(arr[i],arr[j--]);
        else
            i++;
    }

    quickSort(arr,lo,k-1);
    quickSort(arr,i,hi);
}

int main()
{
    int N;
    vector<int> arr;
    cin >> N;
    arr.resize(N);

    for (int i = 0; i < N;i++)
        cin >> arr[i];

    quickSort(arr,0,N-1);

    bool first = false;

    for (int i = 0; i < N;i++)
    {
        if(arr[i]%2!=0)
        {
            //奇数
            if(!first)
                first = true;
            else
                cout << ",";

            cout << arr[i];
        }
    }

        return 0;
}