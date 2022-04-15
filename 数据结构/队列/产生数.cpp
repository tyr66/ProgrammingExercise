#include<iostream>
#include<queue>
using namespace std;

bool mark[10001];
int idcs[20];
int rules[20];

int main()
{
    int N, k;
    cin >> N >> k;

    for (int i = 1; i <= k;i++)
    {
        cin >> idcs[i]>>rules[i];
    }

    queue<int> que;
    que.push(N);
    mark[N] = true;
    int res = 0;

    while(!que.empty())
    {
        int number = que.front();
        que.pop();

        int cpy = number;
        int multiple = 1;
        res++;
        
        do
        {
            int val = cpy % 10;
            int idx = val;
            cpy /= 10;

            for (int i = 1; i <= k;i++)
            {
                if(idcs[i] == idx)
                {
                    int n = (number - val * multiple) + rules[i] * multiple;

                    if (!mark[n])
                    {
                        //cout << n << endl;
                        que.push(n);
                        mark[n] = true;
                    }
                }
            }

            multiple *= 10;
            
        }while(cpy!=0);
    }

    cout << res << endl;

    return 0;
}