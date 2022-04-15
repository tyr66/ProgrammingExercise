#include<iostream>
#include<vector>

using namespace std;

void Hanoi(int n,char src,char mid,char tar)
{
    if(n<=0)
        return;

    Hanoi(n-1,src,tar,mid);
    printf("%c->%d->%c\n",src,n,tar);
    Hanoi(n-1,mid,src,tar);
}

int main()
{
    int n;
    cin >> n;
    char src, mid, tar;
    cin >> src >> tar >> mid;
    Hanoi(n,src,mid,tar);
    return 0;
}