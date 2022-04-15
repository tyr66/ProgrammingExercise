#include<iostream>
using namespace std;

int que[1000004];

int main()
{
    int a, n;

    while(cin>>a>>n)
    {
        int real = 1;
        int two = 1, three = 1;
        que[real] = a;

        while(real<n)
        {
            int t1 = que[two] * 2 + 1;
            int t2 = que[three] * 3 + 1;
            int min_val = min(t1,t2);

            if(t1>t2)
                three++;
            else
                two++;
            
            if(que[real]<min_val)
                que[++real] = min_val;
        }

        cout << que[n]<<endl;
    }

    return 0;
}