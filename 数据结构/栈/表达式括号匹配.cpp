#include<iostream>
#include<stack>
using namespace std;

int main()
{
    char c;
    int count = 0;

    while(true)
    {
        c = getchar();

        if(c == '@')
            break;
        
        if(c=='(')
        {
            count++;
        }
        else if(c == ')')
        {
            count--;
        }
    }

    if(count==0)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}