#include<iostream>

using namespace std;

int upDP[100];
int downDP[100];
int arr[100];

int main()
{

    int N, K;
    cin >> K;

    while(K>0)
    {

        cin >> N;

        for (int i = 0; i < N;i++)
        {
            cin >> arr[i];
        }

        int res = (-2147483647 - 1);
        for (int i = 0; i < N;i++)
        {
            upDP[i] = 1;
            for (int j = 0; j < i;j++)
            {
                if(arr[i]>arr[j])
                {
                    upDP[i] = max(upDP[i],upDP[j]+1);
                }
            }
            res = max(upDP[i],res);
        }

        for (int i = N - 1; i >= 0;i--)
        {
            downDP[i] = 1;
            for (int j = i + 1; j < N;j++)
            {
                if(arr[i]>arr[j])
                {
                    downDP[i] = max(downDP[i],downDP[j]+1);
                }
            }
            res = max(res,downDP[i]);
        }

        cout << res << endl;

        K--;
    }

    return 0;
}