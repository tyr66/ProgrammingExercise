#include<iostream>
#include<string.h>
#include<string>
using namespace std;

char arr_res[10000];
char tmp[101];
char arr_a[100];
char arr_b[100];


void print(int a[],int len)
{
    for (int i = 0; i < len;i++)
    {
        cout << a[i]<<" ";
    }

    cout << endl;
}

void print(char a[],int len)
{
    for (int i = 0; i < len;i++)
    {
        cout << (char)(a[i]+'0')<<" ";
    }

    cout << endl;
}

int decompose(const string& src,char tar[],int len)
{
    int i = 0;
    int src_len = src.size()-1;

    for (; i < src.size()&&i<len;i++)
    {
        tar[i] = src[src_len - i] - '0';
    }
    return i;
}

void slove(const string& a,const string& b)
{
    
    int a_len, b_len;
    int res = 0,res_len =0;

    memset(arr_res,0,sizeof(arr_res));
    memset(arr_a,0,sizeof(arr_a));
    memset(arr_b,0,sizeof(arr_b));

    a_len = decompose(a,arr_a,sizeof(arr_a));
    b_len = decompose(b,arr_b,sizeof(arr_b));

    //print(arr_a,a_len);
    //print(arr_b,b_len);

    int key = 0;

    for (int i = 0; i < b_len;i++)
    {
        int up = 0;
        int tmp_len = 0;
        memset(tmp,0x00,sizeof(tmp));

        for (int j = 0; j < a_len;j++)
        {
            int val = arr_a[j]*arr_b[i]+up;
            tmp[tmp_len++] = val % 10;
            up = val / 10;
        }

        if(up!=0)
            tmp[tmp_len++] = up;

        //print(tmp,tmp_len);
        //进行加法
        up = 0;
        int j = key;
        for (int k = 0; k < tmp_len;j++,k++)
        {
            int val = up + (tmp[k])+(arr_res[j]);
            arr_res[j] = val%10;
            up = val / 10;
        }

        if(up!=0)
            arr_res[j++] = up;

        res_len = j;
        key++;
    }

    for (int i = res_len; i >= 0 && arr_res[i] == 0;i--)
    {
        res_len--;
    }

    for (int i = res_len; i >= 0; i--)
    {
        cout << (char)(arr_res[i] + '0');
    }

    if(res_len <= 0)
        cout <<'0';

    cout << endl;
}

 int main()
{
    
    string a, b;
    cin >> a >> b;

    slove(a,b);

    return 0;
} 

