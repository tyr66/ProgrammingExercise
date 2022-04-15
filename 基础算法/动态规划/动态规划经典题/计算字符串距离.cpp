#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int dp[1001][1001];

int main()
{
    int n;
    cin >> n;
    string a, b;

    while(n>0)
    {
        cin >> a >> b;

        memset(dp,127,sizeof(dp));

        dp[0][0] = 0;

        for (int i = 1; i <= a.size();i++)
            dp[i][0] = i;

        for (int j = 1; j <= b.size();j++)
            dp[0][j] = j;

        for (int i = 1; i <= a.size(); i++)
        {
            for (int j = 1; j <= b.size(); j++)
            {
                if (a[i - 1] == b[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else
                    dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
            }
        }

        cout << dp[a.size()][b.size()]<<endl;

        n--;

    }
}