#include<iostream>
#include<vector>
#include<cstring>
using namespace std;

int bits[32];

int main()
{
    int n;
    vector<int> res;
    while(true)
    {
        cin >> n;

        if(n == 0)
            break;

        memset(bits,0,sizeof(bits));

        int mark = 1;

        for (int i = 0; i < 32;i++)
        {
            if(mark&n)
                bits[i] = 1;
            else
                bits[i] = 0;

            mark = mark << 1;
        }

        int st;
        int count = 0;
        for (int i = 0; i < 32;i++)
            if(bits[i] == 1){
                st = i;
                break;
            }

        for (;st<32&&bits[st]==1;st++,count++)
            ;
        
        if(st<32)
        {
            bits[st] = 1;
            count--;
            for (int i = 0; i < st;i++)
            {
                if(i<count)
                {
                    bits[i] = 1;
                }else
                    bits[i] = 0;
            }
        }

        n = 0;
        mark = 1;
        for (int i = 0; i < 32;i++,mark*=2)
        {
            n += mark * bits[i];
        }

        res.push_back(n);
    }

    for (int i = 0; i < res.size();i++)
        cout << res[i]<<endl;

        return 0;
}