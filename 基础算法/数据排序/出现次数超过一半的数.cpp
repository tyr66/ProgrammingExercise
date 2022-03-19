#include<iostream>
#include<vector>

using namespace std;

int number_hash[101];

int main()
{
    int N;
    vector<int> arr;
    cin >> N;
    arr.resize(N);

    for (int i = 0; i < N;i++)
    {
        cin >> arr[i];
    }

    int res = -100;
    int count = N>>1;
    int id;

    for (int i = 0; i < N;i++)
    {
        id = arr[i] + 50;
        number_hash[id]++;

        if(number_hash[id]>count)
        {
            res = arr[i];
        }
    }

    if(res!=-100)
        cout << res << endl;
    else
        cout << "no"<<endl;

    return 0;
}