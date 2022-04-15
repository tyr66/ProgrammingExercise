#include<iostream>

using namespace std;

int parent[10001];
int price[10001];
int value[10001];
int dp[10001];

int get_parent(int i)
{
    if(parent[i] == i)
        return i;

    parent[i] =  get_parent(parent[i]);
    return parent[i];
}


void Union(int i,int j)
{
    int i_par = get_parent(i);
    int j_par = get_parent(j);

    if(i_par!=j_par)
    {
        parent[i_par] = j_par;
        price[j_par] += price[i_par];
        value[j_par] += value[i_par];
    }
}

int main()
{
    int n, m, w;
    cin >> n >> m >> w;

    for (int i = 1; i <= n;i++)
    {
        cin>>price[i]>>value[i];
        parent[i] = i;
    }

    for (int k = 1; k <= m;k++)
    {
        int i, j;
        cin >> i >> j;
        Union(i,j);
    }

     for (int i = 1; i <= n;i++)
    {
        if(parent[i]!=i)
            continue;
        
        for (int j = w; j >= price[i];j--)
        {
            dp[j] = max(dp[j],dp[j-price[i]]+value[i]);
        }
    }

    cout << dp[w] << endl; 

    return 0;
}