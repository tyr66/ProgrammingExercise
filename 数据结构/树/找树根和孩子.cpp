#include<iostream>

using namespace std;

int parent[101];
int childCount[101];

int main()
{
    int N, K;
    cin >> N >> K;

    int i, j;
    int maxNode, maxChildNums = 0;
    for (int k = 1; k <= K;k++)
    {
        cin >> i >> j;

        parent[j] = i;
        childCount[i]++;

        if(maxChildNums<childCount[i])
        {
            maxNode = i;
            maxChildNums = childCount[i];
        }
    }

    int root = 1;
    for (int i = 1; i <= N;i++)
    {
        if(parent[i] == 0)
        {
            root = i;
            break;
        }
    }
    cout << root << endl;

    cout << maxNode << endl;

    for (int i = 1; i <= N;i++)
    {
        if(parent[i] == maxNode)
            cout << i << " ";
    }

        return 0;
}