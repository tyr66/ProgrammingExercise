#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct  Student
{
    int id;
    int chs;
    int math;
    int eng;
    int total;

    void calTotal()
    {
        total = chs + math + eng;
    }
};

bool operator>(const Student& a,const Student&b)
{
    if(a.total!=b.total)
        return a.total < b.total;
    
    if(a.chs!=b.chs)
        return a.chs < b.chs;


    return a.id > b.id;
}

bool operator<(const Student&a,const Student&b)
{

    if(a.total!=b.total)
        return a.total > b.total;
    
    if(a.chs!=b.chs)
        return a.chs > b.chs;
    
    return a.id < b.id;
}

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
    vector<Student> sts;
    sts.resize(N);

    for (int i = 0; i < N;i++)
    {
        cin >> sts[i].chs >> sts[i].math >> sts[i].eng;
        sts[i].id = i + 1;
        sts[i].calTotal();
    }

    quickSort(sts,0,N-1);

    for (int i = 0; i < 5;i++)
    {
        cout << sts[i].id << " " << sts[i].total<<endl;
    }


    return 0;
}
