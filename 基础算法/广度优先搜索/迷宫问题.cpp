#include<iostream>
#include<queue>
#include<stack>
#include<cstring>
#include<vector>
using namespace std;

int map[5][5];
int parent[5][5];
int step[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

vector<int> getPath()
{
    if(map[0][0] == 1)
        return {};

    vector<int> res;
    queue<int> que;
    que.push(0);
    que.push(0);
    map[0][0] = 1;


    int i, j;
    bool flag = false;
    while(!que.empty())
    {
        i = que.front();
        que.pop();
        j = que.front();
        que.pop();

        if(i == 4&&j ==4)
        {
            flag = true;
            break;
        }

        for (int n = 0; n < 4;n++)
        {
            int n_i = i + step[n][0];
            int n_j = j + step[n][1];

            if(n_i<0||n_i>=5)
                continue;
            if(n_j<0||n_j>=5)
                continue;
            if(map[n_i][n_j] == 1)
                continue;

            map[n_i][n_j] = 1;
            parent[n_i][n_j] = i * 5 + j;
            que.push(n_i);
            que.push(n_j);
        }
    }

    //获取路径
    if(flag)
    {
        stack<int> st;
        i = 4, j = 4;
        while(parent[i][j]!=-1)
        {
            st.push(j);
            st.push(i);
            int val = parent[i][j];
            i = val/5;
            j = val%5;
        }
        st.push(0);
        st.push(0);

        while(!st.empty())
        {
            res.push_back(st.top());
            st.pop();
            res.push_back(st.top());
            st.pop();
        } 
      
    }

    return res;
}

int main()
{


    for (int i = 0; i < 5;i++)
    {
        for (int j = 0; j < 5;j++)
        {
            parent[i][j] = -1;
        }
        
    }

    for (int i = 0; i < 5;i++)
    {
        for (int j = 0; j < 5;j++)
        {
            cin >> map[i][j];
        }
    }

    vector<int> path = getPath();
    //vector<int> path ;

    for (int i = 0; i < path.size();i+=2)
    {
        printf("(%d, %d)\n",path[i],path[i+1]);
    }

    return 0;
}