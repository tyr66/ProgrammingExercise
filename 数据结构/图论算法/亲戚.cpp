#include<iostream>
using namespace std;

/**
 * 思路：并查集：注意这道题输入的数据量很大所以需要快速的读取数据，不能使用cin来读取，只能使用scanf函数来进行读取
 */



int parent[20001];
int height[20001];

int get_parent(int i)
{
    if(parent[i] == i)
        return i;

    parent[i] = get_parent(parent[i]);
    return parent[i];
}



void Union(int i,int j)
{
    int i_par = get_parent(i);
    int j_par = get_parent(j);

    if(i_par == j_par)
        return;
    
    if(height[i_par]>height[j_par])
    {
        parent[j_par] = i_par;

    }else 
    {
        parent[i_par] = j_par;
        
        if(height[i_par] ==  height[j_par])
        {
            height[j_par]++;
        }
    }   

}


bool isUnion(int i,int j)
{
    return get_parent(i) == get_parent(j);
}

int main()
{
    int N, M;
    scanf("%d%d",&N,&M);

    for (int i = 1; i <= N;i++)
    {
        parent[i] = i;
    }

    int from, to;
    for (int i = 0; i < M;i++)
    {
        scanf("%d %d",&from,&to);
        Union(from,to);
    }

    int Q;
    scanf("%d",&Q);

    for (int i = 0; i < Q;i++)
    {
        scanf("%d %d",&from,&to);

        if(isUnion(from,to))
        {
            cout << "Yes\n";
        }else{
            cout << "No\n";
        }
    }
}