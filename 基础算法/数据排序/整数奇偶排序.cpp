#include<iostream>
#include<vector>

using namespace std;

template<typename T>
void quickSort(vector<T>&arr,int lo,int hi)
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
    vector<int> arr;
    arr.resize(10);

    for (int i = 0; i < 10;i++)
        cin >> arr[i];

    int k = 0,i = 0;

    while(i<10)
    {
        if(arr[i]%2!=0)
        {
            swap(arr[i],arr[k++]);

            if(k>i)
                i = k;
        }
        else
            i++;
    }

    quickSort(arr,0,k-1);
    quickSort(arr,k,9);

    for (int i = 0,j = k-1; i < j;i++,j--)
        swap(arr[i],arr[j]);

        for (int i = 0; i < 10; i++)
            cout << arr[i] << " ";
    cout << endl;
    return 0;
}