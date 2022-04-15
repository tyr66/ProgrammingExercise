#include<iostream>
#include<vector>

using namespace std;

bool colHash[8];
vector<int> pos;
int checkboard[8][8];
vector<vector<int>> res;
const int N = 8;
bool check(int i1,int j1)
{
    for (int i = 0; i < i1;i++)
    {
        if(i1-i == j1-pos[i]||i1-i == pos[i] - j1)
            return false;
    }

    return true;
}

void print(int n)
{
    if(n>=res.size())
    {
        return;
    }

    for (int i = 0; i < 8;i++)
    {
        cout << res[n][i]+1;
    }
    cout << endl;
}

void eightQueen(int n)
{

    if(n == N)
    {
        res.push_back(pos);
        return;
    }

    for (int j = 0; j < N;j++)
    {
        if(colHash[j]||!check(n,j))
            continue;

        colHash[j] = true;
        checkboard[n][j] = 1;
        pos[n] = j;
        eightQueen(n+1);
        checkboard[n][j] = 0;
        colHash[j] = false;
    }    
}

int main()
{
    int n;
    vector<int> requst;

    cin >> n;
    requst.resize(n);

    for (int i = 0; i < n;i++)
        cin >> requst[i];
    pos.resize(N);
    eightQueen(0);

    for (int i = 0; i < n;i++)
    {
        print(requst[i]-1);
    }

    return 0;
}