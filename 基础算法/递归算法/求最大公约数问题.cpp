#include<iostream>
#include<vector>

using namespace std;

//辗转相除法:https://blog.csdn.net/so_geili/article/details/54970799
// https://www.zhihu.com/question/51427771
int gdc(int n,int m)
{
    if(m == 0)
    {
        return n;
    }

    return gdc(m,n%m);
}

int main()
{

    int n, m;
    cin >> n >> m;

    if(n<m)
        swap(n,m);

    cout << gdc(n,m)<<endl;

    return 0;
}