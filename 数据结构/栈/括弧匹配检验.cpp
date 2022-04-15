#include<iostream>
#include<string>
#include<stack>
using namespace std;


int main()
{
    stack<char> st;
    bool res = true;
    string str;
    cin >> str;

    for (int i = 0; i <= str.size();i++)
    {
        if(str[i] == '['||str[i] =='(')
        {
            st.push(str[i]);
            continue;
        }        

        if(str[i] == ']'||str[i]==')')
        {
            if(st.empty())
            {
                res = false;
                break;
            }

            if(st.top()=='['&&str[i] == ')')
            {
                res = false;
                break;
            }

            if(st.top()=='('&&str[i] == ']')
            {
                res = false;
                break;
            }

            st.pop();
        }
        
    }

    if(res&&st.empty())
        cout << "OK\n";
    else
        cout << "Wrong\n";

    return 0;
}