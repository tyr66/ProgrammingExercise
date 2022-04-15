#include<iostream>
#include<string>
#include<vector>
using namespace std;

string midOrd;
string preOrd;
vector<int> counts;

void printNode(char c,int len)
{
    for (int i = 0; i < len;i++)
        cout << c;
    cout << endl;
}

int travel(int l,int r,int k)
{
    if(l == r)
    {
        counts[k] = 1;
        return 1;
    }

    int mid;
    int count = 0;
    for (int i = l; i <= r;i++)
    {
        if(midOrd[i] == preOrd[k])
        {
            mid = i;
            break;
        }
    }

    if(mid-1>=l)
        count+=travel(l,mid-1,k+1);
    if(r>=mid+1)
        count+=travel(mid+1,r,k+(mid-l+1));
    
    counts[k] = count;

    return count;
}

int main()
{

    cin >> preOrd >> midOrd;
    counts.resize(preOrd.size());

    travel(0,midOrd.size()-1,0);

    for (int i = 0; i < preOrd.size();i++)
    {
        printNode(preOrd[i],counts[i]);
    }

        return 0;
}