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

    int len_a, len_b;
    len_a = composeArr(str_a,arr_a,sizeof(arr_a));
    len_b = composeArr(str_b,arr_b,sizeof(arr_b));

    int up = 0;
    int i = 0;
    int max_len = max(len_a,len_b);
    int val = 0;
    do
    {
        val = arr_a[i] + arr_b[i] + up;
        up = val / 10;
        arr_a[i] = val%10;
        i++;

    } while (i<max_len||up!=0);

    print(arr_a,i);

    return 0;
}