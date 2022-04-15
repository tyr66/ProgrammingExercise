#include<iostream>
#include<stack>
using namespace std;

int arr[1001];

int main()
{
    int n;
    int val;
    bool res = true;
    cin >> n;
    stack<int> st;

    for (int i = 1; i <= n;i++)
    {
        cin >> arr[i];
    }

    int j = 1;
    for (int i = 1; i <= n;i++)
    {
        if(arr[j]>=i)
        {
            st.push(i);
        }else if(!st.empty()&&arr[j] == st.top()){

            st.pop();
            j++;
            i--;

        }else{

            res = false;
            break;
        }
    }

    //1~n全部入栈，但是还没有判断完
    while(j<=n&&!st.empty()&&arr[j] == st.top())
    {
        j++;
        st.pop();
    }

    if(res&&st.empty()) {
        cout << "YES\n";

    }else{
        cout << "NO\n";
    }

        return 0;
}