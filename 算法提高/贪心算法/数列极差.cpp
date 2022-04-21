#include<iostream>
#include<queue>
#include<vector>
using namespace std;

/**
 * 思路：贪心算法
 * 设有5个整数a_i,a_j,a_k,a_m,a_l那么当数列中只剩下最后一个数时它的值为：
 * a_i*a_j*a_k*a_l*a_m + a_k*a_l*a_m + a_l*a_m + a_m + 1。对于按照规则求出的最后一个值，它的形式都为如此。
 *  对于最后求得的数 a_i*a_j*a_k*a_l*a_m 部分是不变的，那么为了得到最大值就要让剩下的部分最大化，根据贪心原理
 * 当剩下的每一部分都最大化时求出的值为最大值，对于第二部分 a_k*a_l*a_m 当其为最大的三个的乘积时最大化此时对应于第一次
 * 合并最小的两个值，对于其他部分同理以此可以从数学上证明出每次合并最小的两个值可以使得最后求出的值最大。
 * 同理可得每次合并最大的两个值时可以使最后求出的值最小。
 */

int main()
{
    int N;
    cin >> N;
    priority_queue<int,vector<int>,greater<int>> minpq;
    priority_queue<int,vector<int>,less<int>> maxpq;

    for (int i = 0; i < N;i++)
    {
        int n;
        cin >> n;

        minpq.push(n);
        maxpq.push(n);
    }

    
    while(minpq.size()>1&&maxpq.size()>1)
    {
        int a, b;
        a = minpq.top();
        minpq.pop();
        b = minpq.top();
        minpq.pop();
        minpq.push(a*b+1);

        a = maxpq.top();
        maxpq.pop();
        b = maxpq.top();
        maxpq.pop();
        maxpq.push(a*b+1);
        
    }

    cout << minpq.top() - maxpq.top()<<endl;

    return 0;
}