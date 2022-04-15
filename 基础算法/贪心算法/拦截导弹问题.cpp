#include<iostream>

using namespace std;

int sys[1000];

int main()
{
    int height;
    int count = 0;
    while(cin>>height)
    {
        int i = 0;
        for (; i < count;i++)
        {
            if(sys[i]>=height)
            {
                sys[i] = height;
                break;
            }
        }

        if(i == count)
        {
            sys[count] = height;
            count++;
        }

    }

        cout << count << endl;  

    return 0;
}