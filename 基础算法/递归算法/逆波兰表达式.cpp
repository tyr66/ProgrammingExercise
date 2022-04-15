#include<iostream>
#include<vector>
#include<string>
#include<sstream>
#include<stack>

using namespace std;

bool isOperation(const string&str)
{
    if(str.size()!=1)
        return false;
    
    switch (str[0])
    {
        case '+':
            return true;
        case '-':
            return true;

        case '*':
            return true;

        case '/':
            return true;
    }

    return false;
}

double slove()
{
    string str;
    cin >> str;

    if(isOperation(str))
    {
        double a = slove();
        double b = slove();
        switch (str[0])
        {
            case '+':
                return a + b;
            case '-':
                return a - b;
            case '*':
                return a * b;
            case '/':
                return a / b;
        }

    }

    return atof(str.c_str());
}

int main()
{

    printf("%f\n",slove());
    return 0;
}