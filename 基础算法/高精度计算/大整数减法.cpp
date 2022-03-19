#include<iostream>
#include<string>

using namespace std;

char arr_a[300];
char arr_b[300];

int composeArr(const string&src,char*tar,int sz)
{
    int idx = 0;
    int i = 0;

    for (; idx < src.size()&&src[idx] == '0';idx++)
        ;

    //全部都为零时
    if(idx == src.size())
    {
        tar[0] = 0;
        return 1;
    }

    for (int j = src.size()-1;j>=idx&&i<sz;j--,i++)
    {
        tar[i] = src[j]-'0';
    }

    return i;
}

void print(const char*arr,int len)
{
    for (int i = len - 1; i >= 0;i--)
    {
        cout << (char)(arr[i]+'0');
    }

    cout << endl;
}

int main()
{
    string str_a, str_b;
    cin >> str_a >> str_b;

    int len_a = composeArr(str_a,arr_a,sizeof(arr_a));
    int len_b = composeArr(str_b,arr_b,sizeof(arr_b));

    int down = 0;
    int i = 0;
    int min_len = min(len_a,len_b);


    do
    {
        int val = arr_a[i] - arr_b[i] - down;
        arr_a[i] = (val+10) % 10;
        down = val>=0?0:1;
        i++;

    } while (i<min_len||down!=0);

    print(arr_a,max(i,len_a));

    return 0;
}