#include<iostream>

using namespace std;

bool is_Contain(int k,int x)
{
   if(k>x)
        return 0;
    if(k == x)
        return 1;
    return is_Contain((2*k+1), x)||is_Contain((3*k+1),x);
}


int main()
{
    int k, x;
    scanf("%d,%d",&k,&x);

    if(is_Contain(k,x))
        printf("YES");
    else
        printf("NO");
    return 0;
}