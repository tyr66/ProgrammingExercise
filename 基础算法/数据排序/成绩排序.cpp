#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct  Student
{
    string name;
    int grade;
};

bool operator>(const Student& a,const Student&b)
{
    if(a.grade!=b.grade)
        return a.grade < b.grade;

    return a.name.compare(b.name)>0;
}

bool operator<(const Student&a,const Student&b)
{
    if(a.grade!=b.grade)
        return a.grade > b.grade;

    return a.name.compare(b.name)<0;
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
    vector<Student> students;
    cin >> N;

    students.resize(N);

    for (int i = 0; i < N;i++)
        cin >> students[i].name >> students[i].grade;

    quickSort(students,0,N-1);

    for (int i = 0; i < N;i++)
        cout << students[i].name << " " << students[i].grade << endl;


    return 0;
}