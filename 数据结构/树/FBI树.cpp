#include<iostream>
#include<string>
using namespace std;

char get_Type(const string&,int,int);

void travel(const string&str,int l,int r)
{
    if(l ==r)
    {
        cout << get_Type(str,l,r);
        return;
    }

    int mid = (l+r)>>1;

    if(l<=mid)
        travel(str,l,mid);
    if(mid+1<=r)
        travel(str,mid+1,r);

    cout << get_Type(str,l,r);
}

char get_Type(const string&str,int l,int r)
{
    bool hasZero= false;
    bool hasOne = false;

    for (int i = l; i <= r;i++)
    {
        if(str[i] == '0')
        {
            hasZero = true;
        }else if(str[i] == '1')
        {
            hasOne = true;
        }

        if(hasOne&&hasZero)
            break;
    }

    if(hasOne&&hasZero)
        return 'F';
    if(hasOne)
        return 'I';
    return 'B';
}

int main()
{
    int N;
    string str;
    cin >> N>>str;

    travel(str,0,str.size()-1);

    return 0;
}