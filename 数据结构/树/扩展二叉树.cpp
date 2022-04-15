#include<iostream>
#include<string>
using namespace std;

string midOrder;
string bacOrd;

int travel(const string&prev,int i)
{
    if(i>=prev.size())
        return 0;
    
    if(prev[i] == '.')
        return 1;

    int leftCount = travel(prev,i+1);
    midOrder += prev[i];
    int rightCount = travel(prev,i+leftCount+1);
    bacOrd += prev[i];

    return leftCount + rightCount + 1;
}


int main()
{
    string prevOrd;
    cin >> prevOrd;

    travel(prevOrd,0);

    cout << midOrder << endl
         << bacOrd << endl;

    return 0;
}