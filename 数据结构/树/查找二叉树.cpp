#include<iostream>
using namespace std;

struct Node
{
    int left;
    int right;
    int val;
};

Node nodes[101];
int tar, N;
int nums = 0;
bool flag;

void travel(int nodeIdx)
{
    if(nodeIdx == 0)
        return;

    travel(nodes[nodeIdx].left);
    
    if(!flag)
        nums++;
    if(nodes[nodeIdx].val == tar)
        flag = true;

    if(!flag)
    travel(nodes[nodeIdx].right);
}

int main()
{

    cin >> N>>tar;

    for (int i = 1; i <= N;i++)
    {
        cin >> nodes[i].val>>nodes[i].left>>nodes[i].right;
    }

    travel(1);

    cout << nums << endl;

    return 0;
}