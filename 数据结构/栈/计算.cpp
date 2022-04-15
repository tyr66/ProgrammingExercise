#include<iostream>
#include<string>
#include<stack>
#include<math.h>
using namespace std;

string operation = "+-*/^()";

int get_fast(char c)
{
    if(c =='(')
        return -1;

    if(c =='+'||c == '-')
        return 0;
    
    if(c == '/'||c == '*')
        return 1;
    if(c == '^')
        return 2;

    return 3;
}

void cal(stack<int>&number,stack<char>&oper)
{
    if(number.size()<2||oper.empty())
        return;
    
    int b = number.top();
    number.pop();
    int a = number.top();
    number.pop();

    char op = oper.top();


    switch (op)
    {
    case '+':
        number.push(a+b);
        break;
    
    case '-':
        number.push(a-b);
        break;
    
    case '*':
        number.push(a*b);
        break;

    case '/':
        number.push(a/b);
        break;
    
    case '^':
        number.push(pow(a,b));
        break;
    }
}

int main()
{
    stack<char> oper;
    stack<int> number;
    string str;
    bool flag = false;
    int num = 0;

    cin >> str;

    for (int i = 0; i < str.size();i++)
    {
        if(str[i]>='0'&&str[i]<='9')
        {
            num = num * 10 + (str[i] - '0');
            flag = true;
            continue;
        }

        if(flag)
        {
            number.push(num);
            flag = false;
            num = 0;
        }

        //为操作符
        if(operation.find(str[i]) == string::npos)
            continue;
        
        if(str[i] == '(')
        {
            oper.push(str[i]);

        }else if(str[i] == ')')
        {
            while(oper.top()!='(')
            {
                cal(number,oper);
                oper.pop();
            }
            oper.pop();//弹出'('

        }else 
        {
            //持续检查操作符栈的顶层的操作符优先级是否大于或者等于str[i]所代表的操作符的优先级
            while(!oper.empty()&&get_fast(str[i])<=get_fast(oper.top()))
            {
                cal(number,oper);
                oper.pop();
            }
            oper.push(str[i]);
        }     
    }

    if(flag)
    {
        number.push(num);
    }


    while(!oper.empty())
    {
        cal(number,oper);
        oper.pop();
    }

    cout << number.top() << endl;

    return 0;
}