#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

/**
 * 思路：本质上就是求哈夫曼树的WPL(带权路径和)，但是也可以使用贪心的思想来进行思考，
 * 将n个节点合并成一个需要进行n-1次合并，只要每一次合并的时候加上的值最小那么最后得到的
 * 合并值就肯定为最小，因此只要每次找到所有节点中最小的两个顶点进行合并即可。
 */


int main()
{
    priority_queue<int, vector<int>, greater<int>> p_que;
    int N;
    cin >> N;
    for (int i = 0; i < N;i++)
    {
        int tmp;
        cin >> tmp;
        p_que.push(tmp);
    }

    int a, b;
    int res = 0;
    while(p_que.size()>1)
    {
        a = p_que.top();
        p_que.pop();
        b = p_que.top();
        p_que.pop();
        res += a + b;
        p_que.push(a+b);
    }

    cout << res << endl;

    return 0;
}