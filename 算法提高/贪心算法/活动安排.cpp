#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Activity
{
    int s;
    int f;

    bool operator<(const Activity &acti)
    {
        return acti.f > f;
    }

    bool operator>(const Activity &acti)
    {
        return acti.f < f;
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

int main()
{
    int N;
    cin >> N;
    vector<Activity> activities;

    for (int i = 0; i < N; i++)
    {
        int s, f;
        cin >> s >> f;
        activities.push_back({s, f});
    }

    quickSort(activities, 0, N - 1);

    /*  for (int i = 0; i < N;i++)
     {
         printf("%d %d\n",activities[i].s,activities[i].f);
     }
     */
    int ans= 0, f = 0;
    for (int i = 0; i < N;i++)
    {
        if(activities[i].s>=f)
        {
            f = activities[i].f;
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}