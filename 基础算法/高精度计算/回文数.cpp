#include<iostream>
#include<string>

using namespace std;

void print(string&str,int len)
{
    for (int i = 0; i < len;i++)
    {
        cout << (int)(str[i]);
    }
    cout << endl;
}

void toDecimal(string&str,int len,int base)
{
    for (int i = 0; i < len;i++)
    {
        //处理十六进制
        if(base == 16) {

            if(str[i]>='A'&&str[i]<='F')
            {
                str[i] = str[i] - 55;

            }else if(str[i]>='a'&&str[i]<='f')
            {
                str[i] = str[i] - 87;
            }else
            {
                str[i] = str[i] - '0';
            }

        }else{
            str[i] = str[i] - '0';
        }
    }
}


int removeZero(string&str,int len)
{
    int zeroCount = 0;
    int i = 0;
    for (; i < len&&str[i] == '0';i++,zeroCount++)
        ;
    for (; i < len;i++)
    {
        str[i - zeroCount] = str[i];
    }
    return len-zeroCount;
}

bool isPalindrome(const string&str,int len)
{
    for (int i = 0, j = len - 1; i < j;i++,j--)
    {
        if(str[i]!=str[j])
            return false;
    }

    return true;
} 

void reverse(string&str,int len)
{
    for (int i = 0, j = len - 1; i < j;i++,j--)
    {
        swap(str[i],str[j]);
    }
}

int slove(int n,string&src)
{
    string str,revStr;
    int maxSz = str.size() + 30;
    int res_count = 0;
    int len = 0;

    str.resize(maxSz,0);
    str = src;
    len = removeZero(str,str.size());
    toDecimal(str,len,n);

    revStr.resize(maxSz,0);
    revStr = str;
    reverse(revStr,len);

    //print(revStr,len);

    while(res_count<30)
    {
        int up = 0;
        int idx = 0;

        //print(str,len);
        //print(revStr,len);

        do
        {
            int val = str[idx]+revStr[idx]+up;
            up = val / n;
            str[idx] = val%n;
            idx++;

        } while (idx<len||up!=0);

        
        for (int i = 0; i < idx;i++)
        {
            revStr[i] = str[idx-i-1];
        }


        if(isPalindrome(str,idx))
            return res_count+1;

        len = idx;
        res_count++;
    }
    return -1;
}

int main()
{
    int n;
    string str;
    cin >>n;
    cin >> str;

    int res = slove(n,str);


     if(res>0)
    {
        cout << res << endl;
    }else{
        cout << "Impossible"<<endl;
    } 

    return 0;
}