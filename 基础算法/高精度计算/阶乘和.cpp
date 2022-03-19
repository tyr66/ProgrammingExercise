#include<iostream>
#include<string>

using namespace std;

int res[1000];
int factor[1000];

void print(int*arr,int len)
{
    for (int i = len; i >= 1;i--)
        cout << arr[i];
    cout << endl;
}

int main()
{

    int N;
    cin >> N;

    factor[1] = 1;
    factor[0] = 1;
    res[0] = 1;
    res[1] = 1;

    for (int n =2; n <= N;n++)
    {
        int val = 0;
        int up = 0;
        int i = 1;

        for (; i <= factor[0];i++)
        {
            val = factor[i] * n+up;
            factor[i] = val % 10;
            up = val / 10;
        }

        while(up!=0)
        {
            factor[0]+=1;
            factor[factor[0]] = up % 10;
            up /= 10;
        }

        
        int len = max(factor[0],res[0]);
        i = 0;

        do
        {
            ++i;
            val = res[i]+factor[i]+up;
            res[i] = val % 10;
            up = val/ 10;

        } while (i < len||up!=0);

        res[0] = i;
        
       
    }

    print(res,res[0]);

    cout << endl;

    return 0;
}