#include<iostream>
#include<queue>
using namespace std;


int main()
{
    int n, m;
    cin >> n >> m;

    queue<int> que;

    for (int i = 1; i <= n;i++)
    {
        que.push(i);
    }


    while (!que.empty())
    {
        int step = m % que.size();
        step = step == 0 ? que.size():step;

        for (int i = 1; i < step;i++)
        {
            que.push(que.front());
            que.pop();
        }

        cout << que.front() << " ";
        que.pop();
    }
    
}