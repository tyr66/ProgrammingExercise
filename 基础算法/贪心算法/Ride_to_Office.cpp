#include<iostream>
#include<math.h>
using namespace std;

int main()
{

    int n;

    while (cin >> n)
    {
        if(n ==0)
            break;

        float minT = 2147483647;
        float v, t;
        for (int i = 0; i < n;i++)
        {
            cin >> v >> t;

            if(t>=0)
            {
                float tmp_t = 4500 / (1000.0 / 3600.0 * v) + t;
                minT = min(minT,ceil(tmp_t));
            }
        }

        cout << minT << endl;
    }

        return 0;
}