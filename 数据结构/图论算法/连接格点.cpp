#include<iostream>
using namespace std;

struct Point
{
    int x;
    int y;

    bool operator==(const Point&a) const
    {
        return x == a.x && y == a.y;
    }

    bool operator!=(const Point&a) const
    {
        return x != a.x || y != a.y;
    }

};

Point parent[1001][1001];

Point get_parent(int x,int y)
{
    if(parent[x][y].x == x&&parent[x][y].y == y)
        return parent[x][y];

    parent[x][y] = get_parent(parent[x][y].x,parent[x][y].y);

    return parent[x][y];
}



void Union(int x1,int y1,int x2,int y2)
{
    Point par1 = get_parent(x1,y1);
    Point par2 = get_parent(x2,y2);

    if(par1 == par2)
        return ;

    parent[par1.x][par1.y] = par2;
}

int main()
{

    int M,N,total;
    cin >> M>>N;
    for (int i = 1; i <= M;i++)
    {
        for (int j = 1; j <= N;j++)
        {
            parent[i][j] = Point{i,j};
        }
    }

        int x1, y1, x2, y2;

        int res = 0;

        while (scanf("%d %d %d %d", &x1, &y1, &x2, &y2) > 0)
        {
            Union(x1, y1, x2, y2);
        }

   

    for (int i = 1; i < M;i++)
    {
        for (int j = 1; j <= N;j++)
        {
            if(get_parent(i,j)!=get_parent(i+1,j))
            {
                Union(i,j,i+1,j);
                res += 1;
            }
        }
    }

    for (int i = 1; i <= M;i++)
    {
        for (int j = 1; j < N;j++)
        {
            if(get_parent(i,j)!=get_parent(i,j+1))
            {
                Union(i,j,i,j+1);
                res += 2;
            }
        }
    }

    cout << res << endl;

    return 0;
}