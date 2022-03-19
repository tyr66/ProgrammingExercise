#include<iostream>
#include<vector>

using namespace std;

bool number_hash[1001];


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
    int N;
    cin >> N;
    vector<int> arr;

    for (int i = 0; i < N;i++)
    {
        int tmp;
        cin >> tmp;

        if(number_hash[tmp])
            continue;

        number_hash[tmp] = true;
        arr.push_back(tmp);
    }

    quickSort(arr,0,arr.size()-1);
    cout << arr.size() << endl;
    for (int i = 0; i < arr.size();i++)
        cout<<arr[i]<<" ";

    cout << endl;

    return 0;
}