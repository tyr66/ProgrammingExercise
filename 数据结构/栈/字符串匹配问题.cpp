#include<iostream>
#include<stack>
#include<string>
using namespace std;

string order = "<([{";

bool checkOrder(char left,char right)
{
    int left_idx = 0;
    int right_idx = 0;
    while(left_idx < 4)
    {
        if(order[left_idx] == left)
            break;
        left_idx++;
    }

    while(right_idx < 4)
    {
        if(order[right_idx] == right)
            break;
        right_idx++;
    }

    return left_idx >= right_idx;
}

int main()
{
    string str;
    int T;
    cin >> T;

    while(T>0)
    {
        cin >> str;
        stack<char> st;
        bool res = true;

        for (int i = 0; i < str.size()&&res;i++)
        {
            if(str[i] == '<'||str[i] =='('||str[i] == '['||str[i] == '{')
            {
                st.push(str[i]);
                continue;
            }

            if(str[i]=='>')
            {
                if(st.empty()||st.top()!='<')
                {
                    res = false;
                    continue;
                }

                st.pop();

                if(!st.empty()&&!checkOrder(st.top(),'<'))
                    res = false;

            }
            else if(str[i] == ')')
            {
                if(st.empty()||st.top()!='(')
                {
                    res = false;
                    continue;
                }
                st.pop();

                if(!st.empty()&&!checkOrder(st.top(),'('))
                    res = false;

            }
            else if(str[i] == ']')
            {
                if(st.empty()||st.top()!='[')
                {
                    res = false;
                    continue;
                }
                st.pop();
                if(!st.empty()&&!checkOrder(st.top(),'['))
                    res = false;
            }else if(str[i] == '}')
            {
                if(st.empty()||st.top()!='{')
                {
                    res = false;
                    continue;
                }
                st.pop();
                if(!st.empty()&&!checkOrder(st.top(),'{'))
                    res = false;
            }


        }

        if(res&&st.empty())
            cout << "YES\n";
        else
            cout << "NO\n";

        T--;
        
    }

    return 0;
}