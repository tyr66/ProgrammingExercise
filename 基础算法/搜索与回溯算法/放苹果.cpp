#include<iostream>
#include<vector>

using namespace std;

int place(int n,int k)
{
    if(k == 1||n==0)
        return 1;

    if(n>=k)
        return place(n,k-1)+place(n-k,k);
    
    return place(n,n);
}


int main()
{
    vector<int> res;
    int m;
    int n, k;
    cin >> m;

    for (int i = 0; i < m;i++)
    {
        cin >> n >> k;
        res.push_back(place(n,k));
    }

    for (int i = 0; i < m;i++)
        cout << res[i]<<endl;


    return 0;
}
