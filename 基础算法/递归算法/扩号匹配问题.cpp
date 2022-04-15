#include<iostream>
#include<vector>
#include<string>
#include<stack>
using namespace std;


string matchBrackets(const string&str)
{
    stack<int> left;
    stack<int> right;
    string res;
    res.resize(str.size());

    for (int i = 0; i < str.size();i++)
    {
        if(str[i] == '(')
        {
            left.push(i);
        }else if(str[i] == ')')
        {
            if(left.size()>0) {
                left.pop();
            }else {
                right.push(i);
            }
        }

        res[i] = ' ';
    }

    while(left.size()>0)
    {
        res[left.top()] = '$';
        left.pop();
    }

    while(right.size()>0)
    {
        res[right.top()] = '?';
        right.pop();
    }

    return res;
}


int main()
{
    string str;
    vector<string> strs;
    vector<string> res;

    while(cin>>str)
    {
        strs.push_back(str);
        res.push_back(matchBrackets(str));
    }

    for (int i = 0; i < strs.size();i++)
    {
        cout << strs[i]<<endl;
        cout << res[i]<<endl;
    }

    return 0;
}