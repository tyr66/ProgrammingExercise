#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Pond
{
    int value;
    int weak;
    int cost;

    bool operator<(const Pond&b) const 
    {
        return value < b.value;
    }
};



int main()
{
    vector<Pond> ponds;
    int N, T;
    cin >> N >> T;
    T *= 12;
    ponds.resize(N);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < N; j++)
        {
            if (i == 2 && j == N-1)
                break;
            if (i == 0)
                cin >> ponds[j].value;
            else if (i == 1)
                cin >> ponds[j].weak;
            else if (i == 2)
                cin >> ponds[j].cost;
        }
    ponds[N - 1].cost = 0;
    int res = 0;
    int totalCost = 0;
    for (int i = 0;i<N;i++)
    {
        if(totalCost>=T)
            break;

        int t = T - totalCost;
        int ans = 0;
        priority_queue<Pond, vector<Pond>, less<Pond>> pq;

        for (int j = 0; j <= i;j++)
            pq.push(ponds[j]);

        while(t>0&&!pq.empty())
        {
            Pond p = pq.top();
            pq.pop();
            ans += p.value;
            p.value -= p.weak;
            if(p.value>0)
            {
                pq.push(p);
            }
            t--;
        }

        res = max(res,ans);

        totalCost += ponds[i].cost;
    }

    cout << res << endl;

    return 0;
}