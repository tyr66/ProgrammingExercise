#include<iostream>
#include<vector>
using namespace std;

/**
 * 思路：贪心算法：先按照结束区间来进行升序排序，对于一个区域首先查看在其范围内已经种了多少棵树，这些已经种的树为和上一户人家重叠的部分，
 * 如果不够，那么优先在该户最后的区域开始种树，从最后开始种树可以让下一户人家最大化的利用重叠区域
 * 
 */

struct Quest
{
    int B;
    int E;
    int T;

    bool operator<(const Quest&r)
    {
        return E < r.E;
    }

    bool operator>(const Quest&r)
    {
        return E > r.E;
    }
};
template <typename T>
void quickSort(vector<T> &arr, int lo, int hi)
{
    if (lo >= hi)
        return;

    int i, j, k;
    i = lo + 1;
    j = hi;
    k = lo;

    while (i <= j)
    {
        if (arr[k] < arr[i])
            swap(arr[i], arr[j--]);
        else if (arr[k] > arr[i])
            swap(arr[k++], arr[i++]);
        else
            i++;
    }

    quickSort(arr, lo, k - 1);
    quickSort(arr, i, hi);
}

int region[30001];
int main()
{
    int M, N;
    cin >> M >> N;
    vector<Quest> quest;

    for (int i = 0; i < N;i++)
    {
        int b, e, t;
        cin >> b >> e >> t;
        quest.push_back({b,e,t});
    }

    quickSort(quest,0,N-1);

    int ans = 0;
    for (int i = 0; i < N;i++)
    {
        int count = 0;
        for (int j = quest[i].B; j <= quest[i].E;j++)
        {
            if(region[j]==1)
            count++;
        }

        quest[i].T -= count;
        if(quest[i].T<=0)
            continue;
        
        for (int j = quest[i].E; j >= quest[i].B&&quest[i].T>0;j--)
        {
            if(region[j]==0)
            {
                region[j] = 1;
                ans++;
                quest[i].T--;
            }
        }
    }

    cout << ans << endl;
    return 0;
}