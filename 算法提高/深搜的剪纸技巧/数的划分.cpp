#include<iostream>
using namespace std;

int combination(int n,int k,int prev)
{
    if(k == 0)
        return n==0?1:0;
    if(n<prev)
        return 0;

    int count = 0;

    for (int i = prev; i <= n;i++)
    {
        count+=combination(n-i,k-1,i);
    }

    return count;
}

int get_combniatenums(int n,int k)
{
    return combination(n,k,1);
}

int main(){

    int n, k;
    cin >> n >> k;

    cout << get_combniatenums(n,k)<<endl;

    return 0;
}