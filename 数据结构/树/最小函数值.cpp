#include<iostream>
#include<queue>
#include<vector>
using namespace std;

int F[10000][3];
int ans[10000];
priority_queue<int> p_que;

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n;i++)
    {
        cin >> F[i][0]>>F[i][1]>>F[i][2];
    }

    for (int i = 0; i < n;i++)
    {
        for (int x = 1; x <= m;x++)
        {
            int val = F[i][0] * (x * x) + F[i][1] * x + F[i][2];
            //cout << val << endl;
            if(p_que.size()<m)
            {
                p_que.push(val);
            }else if(p_que.top()>val) 
            {
                p_que.pop();
                p_que.push(val);
            }
        }
    }

    //print(p_que);
    n = 0;
    while(!p_que.empty())
    {
        ans[n++] = p_que.top();
        p_que.pop();
    }

    for (int i = n - 1; i >= 0;i--)
        cout << ans[i]<<" ";

        return 0;
}