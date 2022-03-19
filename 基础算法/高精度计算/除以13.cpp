#include<iostream>
#include<string>

using namespace std;

int arr_dividend[100];
int arr_quotient[100];
int remain;

int compose(const string&str,int*tar,int sz)
{
    if(str.size()>sz)
        return -1;

    int j = 0;
    int i = 0;
    for (;j<str.size()&&str[j]=='0';j++)
        ;

    for (; j < str.size();i++,j++)
    {
        tar[i] = str[j] - '0';
    }

    return i;
}


int main()
{
    string str;
    cin >> str;

    int len = compose(str,arr_dividend,sizeof(arr_dividend)/sizeof(int));
    int val = 0;
    bool mark = false;

    for (int i = 0; i < len;i++)
    {
        val = (remain * 10 + arr_dividend[i]);
        arr_quotient[i] = val / 13;
        remain = val % 13;
    }

    for (int i = 0; i < len;i++)
    {
        if(mark||arr_quotient[i]!=0)
        {
            mark = true;
            cout << arr_quotient[i];
        }
    }

    if(mark)
        cout << endl;
    else
        cout << "0" << endl;
    cout << remain << endl;

    return 0;
}