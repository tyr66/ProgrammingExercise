#include<iostream>
#include<string>
using namespace std;



int main()
{
    int n,k;
    string str;
    cin >> n;

    while(n>0)
    {
        cin >> str>>k;

        for (int m = 0; m < k;m++)
        {
            int i = 0;
            int prev = 0;
            for (;i<str.size();i++)
            {
                if(str[i]=='0')
                    continue;
                
                if(str[prev]>str[i])
                {
                    break;
                }

                prev = i;
            }

            str[prev] = '0';
        }

        for (int i = 0; i < str.size();i++)
        {
            if(str[i]!='0')
            {
                cout << str[i];
            }
        }
        
        if(k == str.size())
            cout <<'0';

        cout << endl;
        n--;
    }

    return 0;
}