#include<iostream>
#include<vector>

using namespace std;

string words[20];
int wordsUsedCount[20];
int n;

int overlap(int a,int b)
{
    int res = 0;
    int len_i = words[a].size();
    int len_j = words[b].size();

    if(len_i <=1||len_j<=1)
        return 0;

    for (int i = len_i - 1; i > 0;i--)
    {
        int len = len_i - i;
        if(words[a][i] == words[b][0])
        {
            res = 0;
            for (; res < len_j && res < len;res++)
            {
                if(words[a][res+i] != words[b][res])
                {
                    break;
                }
            }

            if(res == len_j)
            {
                res = 0;
            }

            if(res == len)
            {
                break;
            }else
                res = 0;
        }
    }

    //cout << words[a] << " " << words[b] << " overlap :" << res << endl;

    return res;
}

int solitaire(int k)
{
    int res = words[k].size();

    

    for (int i = 0;i<n;i++)
    {
        if(wordsUsedCount[i]>1)
            continue;

        int overlapLen = overlap(k,i);

        if(overlapLen == 0)
            continue;

        if(overlapLen<words[i].size()&&overlapLen<words[k].size())
        {
            //没有包含关系
            wordsUsedCount[i]++;
            int num = (words[k].size() + solitaire(i) - overlapLen);
            res = max(res,num);
            wordsUsedCount[i]--;
        }
    }

    return res;
}

int Solitaire(char start)
{
    int res = 0;
    for (int i = 0;i<n;i++)
    {
        if(words[i][0] == start)
        {
            wordsUsedCount[i]++;
            res = max(res,solitaire(i));
            wordsUsedCount[i]--;
        }
    }

    return res;
}

int main()
{
    char start;
    cin >> n;

    for (int i = 0; i < n;i++)
    {
        cin >> words[i];
    }

    cin >> start;

    cout<<Solitaire(start)<<endl;

    return 0;
}