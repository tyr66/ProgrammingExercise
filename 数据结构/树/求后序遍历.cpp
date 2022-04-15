#include<iostream>
#include<string>
using namespace std;

string prevOrd;
string midOrd;

void travel(int i,int j,int k)
{
    if(i==j)
    {
        cout << midOrd[i];
        return;
    }

    for (int n = i;n <= j;n++)
    {
        if(midOrd[n] == prevOrd[k])
        {   
            if(i<=n-1)
                travel(i,n-1,k+1);
            if(n+1<=j)
                travel(n+1,j,k+(n-i+1));
            break;
        }
    }

    cout << prevOrd[k];
}

int main()
{
    cin >> prevOrd>>midOrd;

    travel(0,midOrd.size()-1,0);

    return 0;
}