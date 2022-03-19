#include<iostream>
#include<vector>
#include<string>

using namespace std;

struct Student
{
    int id;
    float grade;
} ;

int compare(const Student&a,const Student&b)
{
    if(a.grade>b.grade)
        return -1;
        else if(a.grade<b.grade)
            return 1;
        return 0;
}

int divide(vector<Student>&sts,int st,int ed)
{
    if(st>=ed)
        return st;

    int i = st,lo = st+1,hi = ed;

    while(lo<=hi)
    {
        int val = compare(sts[i],sts[lo]);
        if(val>0)
            swap(sts[i++],sts[lo++]);
        else if(val<0)
            swap(sts[lo],sts[hi--]);
        else
            lo++;
    }

    return i;
}

int main()
{
    vector<Student> students;
    int n, k;
    cin >> n >> k;

    students.resize(n);

    for (int i = 0; i < n;i++)
    {
        cin>>students[i].id>>students[i].grade;
    }

    int lo = 0;
    int hi = n - 1;
    int mid = -1;
    k--;

    while(k !=mid)
    {
        mid = divide(students,lo,hi);

        if(k<mid)
        {
            hi = mid - 1;
        }else if(k>mid)
        {
            lo = mid + 1;
        }

        //cout << mid<< endl;
        //cin >> fir;
    }

    Student &st = students[k];

    printf("%d %g\n",st.id,st.grade);

    return 0;
}
