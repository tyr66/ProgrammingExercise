#include<iostream>
#include<queue>
using namespace std;

int lift[201];
bool mark[201];
int N;

int main()
{
    queue<int> que;
    int start, tar;
    cin >> N>>start>>tar;

    for (int i = 1; i <= N;i++)
        cin >> lift[i];

    int res = 0;
    int count = 1;
    que.push(start);
    mark[start] = true;

    while(!que.empty())
    {
        int p = que.front();
        que.pop();

        if(p == tar)
        {
            break;
        }

        int left = p - lift[p];
        int right = p + lift[p];

        if(left>0&&!mark[left])
        {
            que.push(left);
            mark[left] = true;
        }

        if(right<=N&&!mark[right])
        {
            que.push(right);
            mark[right] = true;
        }

        if(--count == 0)
        {
            res++;
            count = que.size();
        }

    }

    if(mark[tar])
        cout << res << endl;
    else
        cout << "-1" << endl;
    return 0;
}