#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isUsed[100];
int indices[100];//保存每一位的索引
string str;

//dfs原理
void permutate(int idx)
{
    if(idx == str.size())
    {
        for (int i = 0; i < idx;i++)
        {
            cout << str[indices[i]];
        }
        cout << endl;
    }

    for (int i = 0; i < str.size();i++)
    {
        if(!isUsed[i])
        {
            indices[idx] = i;
            isUsed[i] = true;

            permutate(idx+1);
            
            isUsed[i] = false;
        }
    }
}


int main()
{
    cin >> str;

    permutate(0);

    return 0;
}