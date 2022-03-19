#include<iostream>
#include<string>
#include<cstring>

using namespace std;

void slove(int);

char mark[2] = {1,2};
char res_a[100];
char res_copy[100];
char tmp[100];

void print(const char*arr,int len)
{
    for (int i = len; i > 0;i--)
    {
        cout << (char)(arr[i]+'0');
    }

    cout << endl;
}

void add(char*arr,int i,int n)
{
    int up = n;

    do
    {
        int val = arr[i]+up;
        arr[i] = val % 10;
        up = val / 10;
        i++;

    } while (i<=arr[0]||up!=0);
    
    if(arr[0]<(i-1))
    {
        arr[0] = i-1;
    }
}

void mult(char*a_tar,char*b)
{
    int skip = 0;
    memset(tmp,0,sizeof(tmp));
    /* print(a_tar, a_tar[0]);
    print(b,b[0]); */

    for (int n = 1; n <= b[0]; n++)
    {
        int multer = b[n];
        int up = 0;
        int i = 1;

        //进行乘法
        do
        {
            int val = multer * a_tar[i]+up;
            //cout << val << endl;
            add(tmp,i+skip,val%10);
            
            up = val / 10;
            i++;
        } while (i<=a_tar[0]||up!=0);

        //tmp[0] = i-1 + skip;
        skip++;
    }

    //print(tmp,tmp[0]);

    for (int i = 1; i <= tmp[0];i++)
    {
        a_tar[i] = tmp[i];
    }
    a_tar[0] = tmp[0];
}

void multSelf()
{
    res_copy[0] = res_a[0];

    for (int i = 1; i <= res_a[0];i++)
        res_copy[i] = res_a[i];

    mult(res_a,res_copy);
}

void slove(int N)
{

    if(N == 1)
    {
        res_a[0] = 1;
        res_a[1] = 2;
        return;
    }

    slove(N/2);
    multSelf();
    
    if(N%2!=0)
    {
        mult(res_a,mark);        
        return;
    }
}

void test1()
{
    char a[6] = {2,7,1,0,0};
    char b[6] = {2,1,1,0,0};

    mult(a,b);
}

int main()
{
    int N;
    cin >> N;

    slove(N);
    print(res_a,res_a[0]); 

    return 0;
}