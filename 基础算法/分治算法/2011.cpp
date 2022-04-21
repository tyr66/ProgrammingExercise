#include<iostream>
using namespace std;

int number[201];
int N;
bool isOdd()
{
    return number[N-1]%2!=0;
}

bool isOne()
{
    for (int i = 0; i < N-1;i++)
    {
        if(number[i]!=0)
            return false;
    }

    return number[N-1] == 1;
}

void div2()
{
    int perv = 0;
    for (int i = 0; i < N;i++)
    {
        int num = perv * 10 + number[i];

        if(num!=0)
        {
            number[i] = num / 2;
            perv = num % 2;
        }
    }
}

long long mod()
{
    if(isOne())
        return 2011;

    if(isOdd())
    {
        div2();
        long long n = mod();
        return (n*n*2011)%10000;
    }

    div2();
    long long n = mod();
    return (n*n)%10000;
}

int main()
{
    int K;
    cin >> K;

    while(K>0)
    {
        string str;
        cin >> str;

        N = str.size();
        for (int i = 0; i < N;i++)
            number[i] = str[i] - '0';

        cout << mod()<<endl;

        K--;
    }
    return 0;
}