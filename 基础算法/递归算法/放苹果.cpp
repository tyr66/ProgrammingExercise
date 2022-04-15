#include<iostream>
#include<vector>

using namespace std;


int Count(int num,int n,int k)
{
    if(k == 1)
        return 1;

    int res = 0;

    for (int i = num; i <= n;i++)
    {
        if(n-i>=i)
            res += Count(i,n-i,k-1);
    }

    return res;
}

//更优秀的算法
int calculate(int m,int n)
{
    if(m==0||n==1)
        return 1;
    if(m<n)
        return calculate(m,m);
    return calculate(m,n-1)+calculate(m-n,n);
}

int main()
{
    int t,n,m;
    cin >> t;
    vector<int> res;

    for (int i = 0; i < t;i++)
    {
        cin >> n >> m;
        res.push_back(Count(0,n,m));
    }

    for (int i = 0; i < t;i++)
    {
        cout << res[i]<<endl;
    }

        return 0;

}