#include<iostream>
#include<string>
using namespace std;

bool isSymmetric(const string&str,int i)
{

    if(i>=str.size())
        return true;

    int left = i * 2 + 1;
    int right = i * 2 + 2;
    bool res = true;
    char leftChar = left < str.size() ? str[left] : '#';
    char rightChar = right < str.size() ? str[right] : '#';

    if((leftChar=='#'&&rightChar=='#')||(leftChar!='#'&&rightChar!='#'))
    {
        res &= isSymmetric(str,left);

        if(res)
            res &= isSymmetric(str,right);

        return res;
    }

    return false;
}

int main()
{
    string str;
    cin >> str;

    if(isSymmetric(str,0))
    {
        cout << "Yes\n";
    }else
    {
        cout << "No\n";
    }

    return 0;
}