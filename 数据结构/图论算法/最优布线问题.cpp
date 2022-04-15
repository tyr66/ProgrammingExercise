#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;

bool isVis[101];
int lowcost[101];
int adjMat[101][101];
int N;

int prime()
{
    int res = 0;

    memset(lowcost,0x3f,sizeof(lowcost));

    for (int i = 1; i <= N;i++)
    {
        lowcost[i] = adjMat[1][i];
    }

    isVis[1] = true;

    for (int i = 1; i < N; i++)
    {
        int minCost = 0x3f3f3f3f;
        int index = 1;
        for (int j = 1; j <= N;j++)
        {
            if(!isVis[j]&&minCost>lowcost[j])
            {
                minCost = lowcost[j];
                index = j;
            }
        }

        res += minCost;
        if(!isVis[index])
            isVis[index] = true;

        for (int j = 1; j <= N;j++)
        {
            if(!isVis[j]&&lowcost[j]>adjMat[index][j])
            {
                lowcost[j] = adjMat[index][j];
            }
        }
    }

    return res;
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N;i++)
    {
        for (int j = 1; j <= N;j++)
        {
            cin>>adjMat[i][j];
        }
    }

    cout << prime()<<endl;

    return 0;
}