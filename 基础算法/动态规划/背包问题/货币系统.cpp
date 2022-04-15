#include<iostream>
#include<vector>
using namespace std;

/*
3 10       
1          
2           
5   
*/

int main()
{
    vector<long long> dp;
    vector<long long> arr;
    int N, V;
    cin >> N >> V;
    dp.resize(V+1,0);
    arr.resize(N+1);

    for (int i = 1; i <= N;i++)
        cin >> arr[i];

    dp[0] = 1;
    for (int i = 1; i <= N;i++)
    {
        for (int j = arr[i]; j <= V;j++)
        {
            dp[j] = dp[j] + dp[j-arr[i]];
        }
    }

    cout << dp[V] << endl;

    return 0;
}
