#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Student
{
    int id;
    int grade;
};

bool operator>(const Student&a,const Student&b)
{
    if(a.grade!=b.grade)
        return a.grade < b.grade;

    return a.id > b.id;
}

bool operator<(const Student&a,const Student&b)
{
    if(a.grade!=b.grade)
        return a.grade > b.grade;

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

    int N, M;
    cin >> N >> M;
    vector<Student> sts;
    sts.resize(N);

    for (int i = 0; i < N;i++)
    {
        cin >> sts[i].id>>sts[i].grade;
    }

    quickSort(sts,0,N-1);
    M = (M * 1.5f);

    int check_grade = sts[M-1].grade;
    int count = 0;
    for (int i = 0; i < N && sts[i].grade >= check_grade;i++)
    {
        count++;
    }
    cout << check_grade << " " << count<<endl;

    for (int i = 0; i < count;i++)
        cout << sts[i].id << " " << sts[i].grade<<endl;

    return 0;
}
