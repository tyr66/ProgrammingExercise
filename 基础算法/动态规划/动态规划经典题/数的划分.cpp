#include<iostream>

using namespace std;

/**
 * 思路：参考放苹果
 * F(M,N) 表示将M个苹果放在N个盘子上，其中不允许有空盘
 * 按照递归的思想，对于F(M，N) 我们可以分为F(M-N,N) 和F(M-1,N-1)两种子状态之和，前者表示在M个盘子上每一个盘子上的苹果数量都大于等于2
 * 后者表示在M个盘子上至少有一个盘子只有一个苹果
 */

int dp[201][7];

int F(int M,int N)
{
    if(M==N||N==1)
        return 1;

    if(M>=N)
        return F(M-N,N)+F(M-1,N-1);

    return 0;
}

int main()
{

    int M,N;
    cin>>M>>N;

    for(int i =0;i<=M;i++)
    {
        dp[i][i] = 1;
        dp[i][1] = 1;
    }

    for(int i =1;i<=M;i++)
    {
        for(int j =2;j<=N;j++)
        {
            if(i>=j)
                dp[i][j] = dp[i-j][j]+dp[i-1][j-1];
            else 
                dp[i][j] = 0;
        }
    }
    
    cout<<dp[M][N]<<endl;

    return 0;
}