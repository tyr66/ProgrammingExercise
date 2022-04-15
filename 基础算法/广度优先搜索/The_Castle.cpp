#include<iostream>
#include<queue>

using namespace std;

int W, H;
bool mark[50][50];
int rooms[50][50];
int step[4][2] = {{-1,0},{0,1},{1,0},{0,-1}};
int dir[4] = {2,4,8,1};

int bfs(int h,int w)
{
    int roomSize = 0;
    queue<int> que;
    que.push(h);
    que.push(w);

    int i, j;

    mark[h][w] = true;

    while(!que.empty())
    {
        i = que.front();
        que.pop();
        j = que.front();
        que.pop();

        roomSize++;

        for (int n = 0; n < 4;n++)
        {
            int n_i = i + step[n][0];
            int n_j = j + step[n][1];

            //cout << n_i << " " << n_j << endl;

            if(n_i<0||n_i>=H)
                continue;
            if(n_j<0||n_j>=W)
                continue;

            //cout << rooms[i][j]<<" "<<dir[n]<<endl ;
            //有墙
            if(mark[n_i][n_j]||(rooms[i][j]&dir[n]))
                continue;
            
            mark[n_i][n_j] = true;
            que.push(n_i);
            que.push(n_j);
        }
    }

    return roomSize;
}

int main()
{
    cin >> H >> W;
    int roomCount = 0;
    int maxRoomSize = (-2147483647 - 1);

    for (int i = 0; i < H;i++)
    {
        for (int j = 0; j < W;j++)
        {
            cin >> rooms[i][j];
        }
    }

    for (int i = 0; i < H;i++)
    {
        for (int j = 0; j < W;j++)
        {
            if(!mark[i][j])
            {
                maxRoomSize = max(maxRoomSize,bfs(i,j));
                roomCount++;
            }
        }
    }


    cout << roomCount << endl;
    cout << maxRoomSize << endl;

    return 0;
}