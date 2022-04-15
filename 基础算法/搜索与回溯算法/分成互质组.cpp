#include<iostream>
#include<vector>

using namespace std;

int n;
int arrHash[20];
int arr[20];
int res = 2147483647;

int gcd(int n,int m)
{
    if(n<m)
        swap(n,m);
    if(m == 0)
        return n;
    return gcd(m,n%m);
}

void group(int k,int count)
{

    if(k == n)
    {
        res = min(res,count);
        return;
    }

    for (int i = 1; i <= count;i++)
    {
        bool check = true;

        for (int j = 0; j < n&&check;j++)
        {
            if(arrHash[j] == i&&gcd(arr[k],arr[j]) != 1)
            {
                check = false;
                break;
            }
        }

        //都互质
        if(check)
        {
            arrHash[k] = i;
            group(k+1,count);
            arrHash[k] = 0;
        }
    }

    arrHash[k] = count + 1;
    group(k+1,count+1);
    arrHash[k] = 0;
}

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    group(0,0);

    cout << res << endl;

    return 0;
}