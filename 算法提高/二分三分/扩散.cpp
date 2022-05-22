#include <iostream>
#include<cstring>
using namespace std;

/**
 * 思路：二分+并查集
 * 一个点经过t个时间单位后最外层的点为，从起点出发曼哈顿距离为t的所有能到达的点。两个点a,b经过时间t后恰好能到达时，该时间t
 * 即为a,b两点联通的最小时刻，此时必然有a,b的曼哈顿距离等于2t成立，因为设经过时间t后a,b两点通过点 u联通，那么点a到点u的时间
 * 必为t，同样点b到点u 或者说 点u到点b的时间必为t。
 * 
 * 更加详细的解答如下链接所示：
 * http://t.zoukankan.com/wendcn-p-12631958.html
 * https://blog.csdn.net/justidle/article/details/104355432
 */

int x[51], y[51];
int mDist[51][51]; //各个点之间的曼哈顿距离
int parent[51];
int N;

int get_parent(int i)
{
    if(parent[i] == 0)
        return i;

    return parent[i] = get_parent(parent[i]);
}

bool check_union(int i,int j)
{
    return get_parent(i) == get_parent(j);
}

void make_union(int i,int j)
{
    int i_par = get_parent(i);
    int j_par = get_parent(j);

    if(i_par == j_par)
        return;

    parent[i_par] = j_par;
}

bool is_valid(int t)
{
    memset(parent,0,sizeof(parent));

    int count = N;
    for (int i = 1;i<=N;i++)
    {
        for (int j = i + 1; j <= N;j++)
        {
            //cout << check_union(i, j) << endl;
            if(mDist[i][j]<=2*t&&!check_union(i,j))
            {
                //cout << "yes\n";
                make_union(i,j);
                if(--count == 1)
                    return true;
            }
        }
    }


    return false;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> x[i] >> y[i];

    for (int i = 1; i <= N; i++)
    {
        for (int j = i + 1; j <= N; j++)
        {
            mDist[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        }
    }

    int lo=0;
    int hi = 0x3f3f3f3f;

    while(hi - lo>=1)
    {
        int mid = (lo+hi)>>1;

        if(is_valid(mid))
            hi = mid;
        else
            lo = mid+1;
    }

    cout << lo << endl;

    return 0;
}