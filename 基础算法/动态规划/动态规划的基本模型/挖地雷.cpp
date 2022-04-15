#include<iostream>

using namespace std;

int map[200][200];
int path[200][200];

void print(int i,int j)
{
    if(path[i][j]==0)
    {
        printf("%d",i);
        return;
    }

    print(i,path[i][j]);
    printf("-%d",j);

}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n;i++)
    {
        cin>>map[i][i];
    }

    int from, to;
    int maxNum = (-2147483647 - 1);

    while(true)
    {
        cin >> from >> to;

        if(from==0&&to==0)
            break;
        map[from][to] = map[from][from]+map[to][to];
        path[from][to] = from;
    }

    for (int k = 1; k <= n;k++)
    {
        for (int i = 1; i <= k;i++)
        {
            for (int j = k; j <= n;j++)
            {
                if(path[i][k]!=0&&path[k][j]!=0)
                {
                    if(map[i][k]+map[k][j]-map[k][k]>=map[i][j])
                    {
                        map[i][j] = map[i][k] + map[k][j] - map[k][k];
                        path[i][j] = k;
                    }
                }

                if(map[i][j]>maxNum)
                {
                    maxNum = map[i][j];
                    from = i;
                    to = j;
                }
            }
        }
    }

    print(from, to);
    cout << endl<<map[from][to]<<endl;

    return 0;
}