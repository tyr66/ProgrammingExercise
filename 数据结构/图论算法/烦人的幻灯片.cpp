#include<iostream>
#include<vector>
using namespace std;


/**
 * 思路：本质上还是类似于拓扑排序让A，B，C。。。。。个幻灯片和1....n个顶点的包含关系建立一个有向图，
 * 边全部都是由幻灯片指向对应的编号，表示某幻灯片x可以对应于某编号n，我们从编号1开始进行检索，判断该顶点的入度是否为1
 * 如果是那么该编号顶点所连接幻灯片即为其对用的幻灯片，然后删除和该幻灯片链接的所有边。如果其过程产生了一个入度为1的编号顶点，那么就基于该顶点
 * 继续执行上述操作。在此过程中如果所有编号顶点的入度都能变为1，那么幻灯片和编号之间就由唯一的对应关系，就存在多组对用关系(算法过程中无法再产生入度为1
 * 的编号顶点)，或者没有对应关系(算法过程中有编号顶点的入度变为0)。
 */

int link[27][27];
int in_degree[27];
int xmin[27];
int xmax[27];
int ymin[27];
int ymax[27];
int sum = 0;
int res[27];
int N;

void Find(int k)
{
    for (int i = 1; i <= N;i++)
    {
        if(link[i][k] == 1)
        {
            res[i] = k;
            link[i][k] = 0;
            in_degree[k]--;
            sum++;
            int index = 0;

            for (int j = 1; j <= N;j++)
            {
                if(link[i][j] == 1)
                {
                    link[i][j] = 0;
                    in_degree[j]--;

                    if(in_degree[j] ==1)
                    {
                        index = j;
                    }
                }
            }

            if(index!=0)
                Find(index);

            break;
        }
    }
}


int main()
{
    cin >> N;

    for (int i = 1; i <= N;i++)
    {
        cin >> xmin[i] >> xmax[i]>>ymin[i]>>ymax[i];
    }

    for (int i = 1; i <= N;i++)
    {
        int x, y;
        cin >> x >> y;

        for (int j = 1; j <= N;j++)
        {
            if(x>=xmin[j]&&x<=xmax[j]&&y<=ymax[j]&&y>=ymin[j])
            {
                link[j][i] = 1;
                in_degree[i]++;
            }
        }
    }

    for (int i = 1; i <= N;i++)
    {
        if(in_degree[i] == 1)
        {
            Find(i);
        }
    }

    if(sum!=N)
    {
        cout << "None\n";
        return 0;
    }

    for (int i = 1; i <= N;i++)
    {
        printf("%c %d\n",'A'+(i-1),res[i]);
    }

        return 0;
}