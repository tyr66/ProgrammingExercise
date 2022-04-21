#include <iostream>
#include <vector>
#include<math.h>
using namespace std;

struct Interval
{
    double s;
    double f;
};

int main()
{
    int T;
    cin >> T;

    while (T > 0)
    {
        int N;
        double L, W;
        cin >> N >> L >> W;
        vector<Interval> intervals;
        for (int i = 0; i < N; i++)
        {
            float p, r;
            cin >> p >> r;
            if(r<=W/2)
                continue;
            float dist = sqrt(r * r - (W * 0.5f * W * 0.5f));
            intervals.push_back({p - dist, p + dist});
        }

        double f = 0;
        int ans = 0;
        for (int i = 0; i < intervals.size()&&f<L; i++)
        {
            bool flag = false;
            double maxF = f;
            for (int j = 0; j < intervals.size(); j++)
            {
                if (intervals[j].s <= f && intervals[j].f > maxF)
                {
                    maxF = intervals[j].f;
                    flag = true;
                }
            }

            if (flag)
            {
                f = maxF;
                ans++;
            }
            else
                break;
        }

        if (f >= L)
            cout << ans << endl;
        else
            cout << "-1" << endl;

        T--;
    }
    return 0;
}