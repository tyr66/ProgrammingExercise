#include<iostream>

using namespace std;

/*
思路：不难发现，如果n==2，使用时间为小的那个数
      如果n>2，使用时间为总时间/2
*/

int main()
{
    int n;
    float ans ;

    while (cin >> n)
    {
        int t =0, f=0;
        ans = 0.0f;
        float val;

        if(n==2)
        {
            cin >> ans >> val;
            ans = min(ans,val);
        }else
        {
            for (int i = 0; i < n;i++)
            {
                cin >> val;
                ans += val;
                
            }
            ans /= 2;
        }

        printf("%.1f\n", ans);
    }

        return 0;
}