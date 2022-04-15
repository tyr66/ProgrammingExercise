#include<iostream>
#include<vector>

using namespace std;

string memory[20001];

void decompose(int n,string&res)
{
    if(n == 1||n==0||n==2)
    {
        res += memory[n];
        return;
    }
    if(memory[n].size()!=0)
    {
        res += memory[n];
        return;
    }

    int i = 1,j = 0;
    for (; i < n;i*=2,j++)
        ;

    

    for (;n!=0;)
    {
        if(n>=i)
        {
            //cout << "i = "<<i<<" j = "<<j<<endl;
            n -= i;
            if(memory[i].size()==0)
            {
                res += "2(";
                decompose(j,res);
                res += ")";
            }
            else
                res += memory[i];
            res += "+";
        }

        i = i >> 1;
        j--;
    }

    res.pop_back();
    memory[n] = res;
}

int main()
{
    int n;
    cin >> n;

    string res;

    memory[0] = "0";
    memory[1] = "2(0)";
    memory[2] = "2";

    decompose(n,res);

    
    cout << res << endl;

    return 0;
}