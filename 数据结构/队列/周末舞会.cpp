#include<iostream>
using namespace std;

int main()
{
    int n, m;
    int K;
    cin >> n >> m;
    cin >> K;

    for (int k = 1; k <= K;k++)
    {
        int i = k % n;
        int j = k % m;

        i = i == 0 ? n : i;
        j = j == 0 ? m : j;

        printf("%d %d\n",i,j);
    }

    return 0;
}