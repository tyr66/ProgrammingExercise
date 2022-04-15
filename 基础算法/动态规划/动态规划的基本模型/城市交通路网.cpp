#include<iostream>

using namespace std;

int map[100][100];
int path[100][100];

#define I_MAX 2147483647

void print(int i,int j)
{
    if(path[i][j] == -1)
    {
        printf("%d ",i+1);
        return;    
    }

    print(i,path[i][j]);
    printf("%d ",j+1);
}

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n;i++)
    {
        for (int j = 0; j < n;j++)
        {
            cin >> map[i][j];

            if(map[i][j] ==0)
            {
                map[i][j] = I_MAX;
                path[i][j] = -1;
            }else
            {
                path[i][j] = i;
            }
        }
    }

    for (int k = 0; k < n;k++)
    {    
        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j < n;j++)
            {
                if(map[i][k]!=I_MAX&&map[k][j]!=I_MAX)
                {
                    if(map[i][j]>map[i][k]+map[k][j])
                    {
                        map[i][j] = map[i][k]+map[k][j];
                        path[i][j] = k;
                    }
                }
            }
        }
    }

    printf("minlong=%d\n",map[0][n-1]);
    print(0,n-1);

    return 0;
}