#include<iostream>
#include<vector>

using namespace std;

long long memory[1001];

long long solve(int n)
{
    int half_n = n >> 1;
    long long res = 1;

    if(memory[n]!=0)
        return memory[n];

    if(half_n == 0)
        return 1;


    for (int i = 1; i <= half_n;i++)
        res += solve(i);

    memory[n] = res;

    return res;
}

int main()
{
    int n;
    cin >> n;

    cout << solve(n)<<endl;

    return 0;
}