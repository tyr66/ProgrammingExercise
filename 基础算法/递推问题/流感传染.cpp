#include<iostream>
#include<vector>

using namespace std;

char room[100][100];

int neighbors[4][2] = {{0,1},{1,0},{0,-1},{-1,0}};

int main()
{
    int sz;
    int day;
    cin >> sz;

    vector<int> infects;

    for (int i = 0; i < sz;i++)
    {
        for (int j = 0; j < sz;j++)
        {
            cin >> room[i][j];

            if(room[i][j] == '@')
            {
                infects.push_back(i);
                infects.push_back(j);
            }
        }
    }

    cin >> day;

    int N = infects.size();
    for (int d = 0; d < day-1;d++)
    {
        for (int n = 0; n < N;n+=2)
        {
            for (int k = 0; k < 4;k++)
            {
                int i = infects[n] + neighbors[k][0];
                int j = infects[n + 1] + neighbors[k][1];

                if(i<0||j<0||i>=sz||j>=sz)
                    continue;

                if(room[i][j] == '.')
                {
                    room[i][j] = '@';
                    infects.push_back(i);
                    infects.push_back(j);
                }
            }
        }

        N = infects.size();
    }

    cout << (infects.size()>>1)<<endl;

    return 0;
}