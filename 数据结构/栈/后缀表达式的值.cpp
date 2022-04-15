#include<iostream>
#include<stack>
#include<string>

using namespace std;



int main()
{

    char c;
    stack<long long int> st;
    long long int num=0;
    bool flag = false;

    while(true)
    {

        scanf("%c",&c);

        if(c == '@')
            break;
        
        if(c>='0'&&c<='9')
        {
            num = num * 10 + (c -'0');
            flag = true;
        }else if(c!=' '){

            long long int b = st.top();
            st.pop();
            long long int a = st.top();
            st.pop();

            switch (c)
            {
                case '+':
                    st.push(a+b);
                    break;
                case '-':
                    st.push(a - b);
                    break;
                case '*':
                    st.push(a*b);
                    break;
                case '/':
                    st.push(a/b);
                    break;
            }

        }else if(flag){
            st.push(num);
            num = 0;
            flag = false;
        }

    }

    if(!st.empty())
        printf("%lld\n",st.top());

    return 0;
}