#include<iostream>
#include<string>
using namespace std;

//注意删除前导零

int main()
{
    int n;
    string str;
    cin >> str;
    cin >> n;

    for (int i = 1; i <= n;i++)
    {
        int j = 0;
        bool isFind = false;

        for (; j < str.size()-i;j++)
        {
            if(!isFind&&str[j]>str[j+1])
                isFind = true;
            if(isFind)
                swap(str[j],str[j+1]);
        }

    }

    bool flag = false;
    for (int i = 0; i < str.size()-n;i++)
    {
        if(!flag&&str[i] == '0')
            continue;

        flag = true;
        cout << str[i];
    }

    if(n == str.size())
        cout << "0";

    cout << endl;

    return 0;
}