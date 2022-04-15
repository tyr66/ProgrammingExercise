#include<iostream>
#include<vector>

using namespace std;

vector<int> res;
int n, k;

void combination(int m,int len)
{
    if(len == 0)
    {
        for (int i = 0; i < k;i++)
            cout <<"  "<< res[i];
        cout << endl;
        return;
    }

    for (int i = m+1; i <= (n-len+1);i++)
    {
        res[k - len] = i;
        combination(i,len-1);
    }
}

int main()
{

    cin >> n >> k;
    res.resize(k);
    combination(0,k);

    return 0;
}