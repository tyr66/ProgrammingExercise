#include<iostream>
#include<algorithm>
using namespace std;

/*
思路：将所有点依照y值从大到小排序，如果y值相同则依照从x值从大到小排序
从0开始遍历数组，记录遇到的点最大的x值 max，如果有点大于该值则该点为一个极点，然后更新max。
直至数组结尾
*/

struct Point
{
    int x;
    int y;
};

bool cmp(const Point&a,const Point&b)
{
    if(a.y==b.y)
        return a.x>b.x;
    return a.y > b.y;
}

Point points[100];

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n;i++)
    {
        cin >> points[i].x >> points[i].y;
    }

    sort(points, points + n,cmp);

    int max = (-2147483647 - 1);
    bool flag = true;

    for (int i = 0; i < n;i++)
    {
        if(points[i].x>max)
        {
            max = points[i].x;

            if(flag)
            {
                //第一次输出
                printf("(%d,%d)",points[i].x,points[i].y);
                flag = false;
            }else
            {
                printf(",(%d,%d)",points[i].x,points[i].y);
            }

        }
    }

    return 0;
}