#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct Item
{
    double aver;
    float v;
    float w;
};

Item items[100];

bool cmp(const Item&a,const Item&b)
{
    return a.aver > b.aver;
}

int main()
{
    int k;
    cin >> k;

    vector<double> res;

    while(k>0)
    {
        float w;
        int s;
        double val = 0.0f;
        cin>>w >> s;

        for (int i = 0; i < s;i++)
        {
            cin >> items[i].w>>items[i].v;
            items[i].aver = (double)items[i].v/ items[i].w;
        }

        sort(items,items+s,cmp);

        for (int i = 0; i < s&&w>0;i++)
        {
            float tmp = min(w,items[i].w);
            val += tmp * items[i].aver;
            w -= tmp;
        }

        printf("%.2f\n",val);

        k--;
    }

    return 0;
}