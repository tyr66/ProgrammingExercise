#include<iostream>
#include<vector>

using namespace std;

char map[100][100];
vector<bool> res;
int src_i, src_j;
int n, k;
int tar_i, tar_j;
int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

//使用不需要回退的dfs，否则会超时
//为什么不需要进行回退？
//原因是我们不是在寻找最短的路径，我们不需要多次的遍历一个点来优化路径。
//只要找到了路径就可以返回
//这种对应的题目一般是“是否能走到”、“有无一种方案能够到达”等。因为我们的目的是找到终点，
//所以不需要像上面那样穷尽所有的方案，我们只要找到了，那么就停止搜索了。比如我们一条路走不通了，
//那么我们回去，并且在回去的路上，我们用土把这些走过的地方填上，以后就不走这儿了
bool reachability(int i,int j)
{

    if(i==tar_i&&j==tar_j)
        return true;

    bool res = false;

    map[i][j] = '#';

    for (int k = 0; k < 4&&!res;k++)
    {
        int to_i = i+step[k][0];
        int to_j = j+step[k][1];

        if(to_i<0||to_i>=n)
            continue;
        
        if(to_j<0||to_j>=n)
            continue;

        if(map[to_i][to_j] == '.')
            res = res || reachability(to_i,to_j);
    }

    return res;
}

int main()
{
    cin >> k;

    while(k>0)
    {
        cin >> n;
        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j < n;j++)
            {
                cin >> map[i][j];
            }
        }

        cin >> src_i>>src_j;
        cin >> tar_i >> tar_j;

        if(map[src_i][src_j] =='#'||map[tar_i][tar_j] == '#')
            res.push_back(false);
        else
            res.push_back(reachability(src_i,src_j));

        k--;
    }


    for (int i = 0; i < res.size();i++)
    {
        if(res[i])
            cout << "YES\n";
        else
            cout << "NO\n";
    }

        return 0;
}