#include <iostream>
#include <string>
#include<cstring>
#include <queue>
#include<sstream>
using namespace std;

/**
 * 思路：宽度优先搜索或者是最短路径算法
 *  此题输入存在bug 
 */

int cost[1000][1000];
bool isVis[1000];
int bus[1000];


int bfs(int N)
{
    queue<int> que;
    que.push(1);
    isVis[1] = true;
    int count = 1;
    int res = 0;

    while (!que.empty())
    {
        int n = que.front();
        que.pop();

        if (n == N)
            break;

        for (int i = 1; i <= N; i++)
        {
            if (isVis[i] || !cost[n][i])
                continue;

            que.push(i);
            isVis[i] = true;
        }

        if ((--count) == 0)
        {
            res++;
            count = que.size();
        }
    }

    return isVis[N] ? res-1 : -1;
}

int main()
{
    int M, N;
    scanf("%d %d\n",&M,&N);
    
    //一定要使用这种输入方式，否则不通过
    for(int i=0;i<M;i++){
        string s;
        getline(cin,s);
        stringstream ss;
        ss<<s;
        int flag=0;
        int t;
        while(ss>>t){
            bus[flag]=t;
            flag++;
        }
        for(int j=0;j<flag;j++){
            for(int k=j+1;k<flag;k++){
                cost[bus[j]][bus[k]]=1;
            }
        }
    }
   
    int res = bfs(N);

    if (res == -1)
    {
        cout << "NO";
    }
    else
    {
        cout << res;
    }  

    //cout << "NO";

    return 0;
}