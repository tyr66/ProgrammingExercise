#include<iostream>
#include<string.h>
#include<string>
using namespace std;

char arr_dividend[300];//被除数
char arr_divisor[300];//除数
char arr_quotient[300];//商

int decompose(const string& src,char tar[],int sz)
{
    int res = 0;
    int len = src.size();
    int i = 0;

    //消除前导零
    for (; i < len&&src[i] == '0';i++)
        ;

    for (; i < len && i < sz; i++, res++)
    {
        tar[len - i - 1] = src[i] - '0';
    }

    return res;
}

int compare(char*arr_a,int len_a,char* arr_b,int len_b,int offset)
{

    if((len_b+offset)>len_a)
        return -1;
    else if((len_b+offset)<len_a)
        return 1;

    //位数相同
    int i = len_a - 1;
    int j = len_b - 1;
    for (; i >= 0&&j>=0;i--,j--)
    {
        if(arr_a[i]<arr_b[j])
            return -1;
        else if(arr_a[i]>arr_b[j])
            return 1;
    }

    return 0;
    
}

//重新调整长度
int readjustLen(char*arr,int len)
{
    for (;arr[len-1] == 0&&len>0;len--)
        ;

    return len;
}

int calDiff( char*arr_a,int len_a, char*arr_b,int len_b)
{
    if(len_b>len_a)
        return 0;

    int len_diff = len_a - len_b;
    while(compare(arr_a,len_a,arr_b,len_b,len_diff)<0&&len_diff>0)
        len_diff--;

    return len_diff;
}

int getLen(char*arr,int sz)
{
    int i = sz - 1;
    for (; i >= 0&&arr[i] == 0;i--)
        ;

    return i + 1;
}

void print_arr(char*arr,int len)
{
    if(len == 0)
        cout <<'0';

    for (int i = len - 1; i >= 0;i--)
    {
        cout << (char)(arr[i]+'0');
    }
    cout << endl;
}

void addZero(char*arr,int sz,int step)
{
   
   if(step==0)
       return;

    for (int i = sz-1; i >=step;i--)
    {
        arr[i] = arr[i - step];
    }

    for (int i = 0; i < step;i++)
    {
        arr[i] = 0;
    }

}

void slove(const string&a,const string&b)
{
    memset(arr_quotient,0,sizeof(arr_quotient));
    memset(arr_dividend,0,sizeof(arr_dividend));
    memset(arr_divisor,0,sizeof(arr_divisor));

    int len_dd, len_dr,len_quo;
    int len_diff;

    len_dd = decompose(a,arr_dividend,sizeof(arr_dividend));
    len_dr = decompose(b,arr_divisor,sizeof(arr_divisor));
    len_quo = 0;
    len_diff = calDiff(arr_dividend,len_dd,arr_divisor,len_dr);
    //cout << len_diff<<endl;
    //print_arr(arr_dividend,len_dd);
    //print_arr(arr_divisor,len_dr);

   while(compare(arr_dividend,len_dd,arr_divisor,len_dr,len_diff)>=0)
    {
        //进行减法
        int down = 0;
        for (int i = 0; i < len_dr||down!=0;i++)
        {
            int val = arr_dividend[i + len_diff] - arr_divisor[i] - down;
            arr_dividend[i+len_diff] = (10+val)%10;
            down = val >= 0 ? 0 : 1;
        }

        //调整长度
        int step = len_diff;
        len_dd = readjustLen(arr_dividend,len_dd);
        len_diff = calDiff(arr_dividend,len_dd,arr_divisor,len_dr);

        //对商进行加法
        int j = 0;
        int up = 1;

        do
        {
            int val = arr_quotient[j]+up;
            arr_quotient[j] = val % 10;
            up = val / 10;
            j++;
        } while (up!=0);

        //添加零
        step = step - len_diff;
        addZero(arr_quotient,sizeof(arr_quotient),step);
    }

    len_quo = getLen(arr_quotient,sizeof(arr_quotient)); 
    print_arr(arr_quotient,len_quo);
    print_arr(arr_dividend,len_dd);
}


int main()
{
    string a,  b;
    cin >> a >> b;

    slove(a,b);

    return 0;
}