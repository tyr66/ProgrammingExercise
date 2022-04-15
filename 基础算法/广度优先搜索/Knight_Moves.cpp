#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

struct Point
{
    Point(int _i,int _j)
    {
        i = _i;
        j = _j;
    }
    Point()
    {

    }
    int i, j;
};

char map[300][300];
int step[8][2] = {{-2,1},{2,1},{2,-1},{-2,-1},{1,2},{-1,2},{-1,-2},{1,-2}};
int n;

int getMinStep(const Point&st,const Point&ed)
{
    if(st.i == ed.i&&st.j == ed.j)
        return 0;

    queue<Point> que;
    que.push(st);
    int count = 1;
    int res = 0;

    Point p;

    while(!que.empty())
    {
        p = que.front();
        que.pop();

        if(p.i ==ed.i&&p.j == ed.j)
        {
            break;
        }

        for (int k = 0; k < 8;k++)
        {
            Point tmp = Point(p.i+step[k][0],p.j+step[k][1]);

            if(tmp.i<0||tmp.i>=n)
                continue;
            if(tmp.j<0||tmp.j>=n)
                continue;
            if(map[tmp.i][tmp.j] == 1)
                continue;

            map[tmp.i][tmp.j] = 1;
            que.push(tmp);
        }

        if(--count == 0)
        {
            res++;
            count = que.size();
        }
    }

    return res;
}

void cleanMap(int n)
{
    for (int i = 0; i < n;i++)
    {
        memset(map[i],0,n);
    }
}

int main()
{
    int k;
    cin >> k;
    Point st, ed;

    while(k>0)
    {
        cin >> n;
        cin >> st.i >> st.j >> ed.i >> ed.j;

        cleanMap(n);
        int minStep = getMinStep(st,ed);
        cout <<minStep<<endl;
        k--;
    }

    return 0;
}