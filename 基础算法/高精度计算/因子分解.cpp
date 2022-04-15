#include<iostream>
#include<vector>

using namespace std;

int depth;

void decompose(int n,int factor)
{
    if(n == 1)
        return;

    depth++;

    for (int i = factor; i <= n;i++)
    {
        if(n%i==0)
        {
            
            if(depth!=1)
            {
                if(i == factor)
                    printf("^");
                else
                    printf("*");
            }
            printf("%d",i);
            decompose(n/i,i);
            break;
        }
    }
}

int main()
{

    for (int n = 2; n <= 100;n++)
        {
            depth = 0;
            decompose(n, 2);
            cout << endl;
        }
    return 0;
}