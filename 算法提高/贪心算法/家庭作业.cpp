#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


/**
 * 思路：贪心算法
 * 该题思路不难，但是一般解决方案会超时。所以关键是如何进行优化，我们通过设置一个
 * dislike变量来实时记录当前已经排满的时间段，当作业的完成时间小于该时间段的时候
 * 表示该任务不能被完成
 */

struct Work
{
    int t;
    int v;
};

bool cmp(const Work&a,const Work&b)
{
    return a.v > b.v;
}
bool isUsed[1000001];

int main()
{
    vector<Work> works;
    int N;
    cin >> N;

    for (int i = 0; i < N;i++)
    {
        int t, v;
        cin >> t >> v;
        works.push_back({t,v});
    }

    sort(works.begin(),works.end(),cmp);

    int res = 0;
    int dislike = 0;
    for (int i = 0; i < N;i++)
    {
        if(dislike>=works[i].t)
            continue;
        bool flag = false;
        for (int j = works[i].t; j >= 1;j--)
        {
           
            if(!isUsed[j])
            {
                flag = true;
                isUsed[j] = true;
                res += works[i].v;
                break;
            }
        }

        if(!flag)
        {
            dislike = works[i].t;
        }
    }

    cout << res << endl;

    return 0;
}