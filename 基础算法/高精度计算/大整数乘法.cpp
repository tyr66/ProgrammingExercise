#include<iostream>
#include<string>
#include<cstring>

using namespace std;

void slove(int);

char arr_a[40000];
char arr_b[200];
char res[40000];
int len_res;

void print(const char*arr,int len)
{
    for (int i = len-1; i >= 0;i--)
    {
        cout << (char)(arr[i]+'0');
    }

    cout << endl;
}

int add(char*arr,int len,int i,int n)
{
    int up = n;

    do
    {
        int val = arr[i]+up;
        arr[i] = val % 10;
        up = val / 10;
        i++;

    } while (i<len||up!=0);

    return len < (i) ? i: len;
}



void mult(char*a_tar,int len_a,char*b,int len_b)
{
    int skip = 0;
    /* print(a_tar, a_tar[0]);
    print(b,b[0]); */

    for (int n = 0; n < len_b; n++)
    {
        int multer = b[n];
        int up = 0;
        int i = 0;

        //进行乘法
        do
        {
            int val = multer * a_tar[i]+up;
            //cout << val << endl;
            len_res = add(res,len_res,i+skip,val%10);
            up = val / 10;
            i++;
        } while (i<len_a||up!=0);

        //tmp[0] = i-1 + skip;
        skip++;
    }

    
}

int compose(const string&str,char*tar,int sz)
{
    if(str.size()>sz)
        return -1;

    for (int i = 0, j = str.size() - 1; j >= 0;i++,j--)
    {
        tar[i] = str[j] - '0';
    }

    return str.size();
}

int main()
{
    string a, b;
    cin >> a >> b;

    int len_a = compose(a,arr_a,sizeof(arr_a));
    int len_b = compose(b,arr_b,sizeof(arr_b));

    //print(arr_a,len_a);
    //print(arr_b,len_b);

    mult(arr_a,len_a,arr_b,len_b);
    print(res,len_res);

    return 0;
}