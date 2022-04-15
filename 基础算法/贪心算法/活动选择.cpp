#include<iostream>

using namespace std;

int arr[1000][2];

int main()
{
    int n;
    cin >> n;
    int res = 0;

    for (int i = 0; i < n;i++)
    {
        cin >> arr[i][0];
        cin >> arr[i][1];
    }

    int left = 0;
    bool flag = false;


    while(true)
    {
        flag = false;
        int minRight = 2147483647;

        for (int i = 0; i < n;i++)
        {
            if(arr[i][0]>=left&&arr[i][1]<minRight)
            {
                flag = true;
                minRight = arr[i][1];
            }
        }

        if (!flag)
            break;

        left = minRight;
        res++;
        
    }

    cout << res << endl;

    return 0;
}