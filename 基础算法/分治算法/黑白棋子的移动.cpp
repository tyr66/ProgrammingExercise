#include<iostream>
using namespace std;

/**
 * 思路：分治算法
 * 我们先从 n=4 开始试试看，初始时∶○○○○●●●●
        第1步∶○○○--●●●○●              { - 表示空位 }

        第2步∶○○○●○●●--●

        第3 步∶○--●○●●○○●

        第4步∶○●○●○●--○●

        第5步∶--○●○●○●○●

        如果 n=5 呢?我们继续尝试，希望看出一些规律，初始时∶○○○○○●●●●●

        第1步∶○○○○●●●●○●

        第 2步∶○○○○●●●●--○●

        这样，n=5的问题又分解成了n=4 的情况，下面只要再做一下 n=4 的5 个步骤就行了。同理，n=6 的情况又可以分解成 n=5 的情况，…，
        所以，对于一个规模为 n 的问题，我们很容易地就把它分治成了规模为 n-1 的相同类型子问题。

        数据结构如下∶数组 c[1..max]用来作为棋子移动的场所，初始时，c[1]～c[n] 存放白子（用字符o表示），c[n+1]～c[2n] 存放黑子
        （用字符*表示），c[2n+1]，c[2n+2]为空位置（用字符 - 表示）。最后结果在 c[3]～c[2n+2]中。
 * 
 */

char arr[1000001];
int N;

void print()
{
    static int count = 0;
    printf("step%2d:",count++);
    for (int i = 0; i < 2*N+2;i++)
    {
        cout << arr[i];
    }
    cout << endl;
}

int k;
void move(int n)
{
    for (int i = 0; i < 2;i++)
    {
        swap(arr[k+n+i],arr[k+i]);
    }
    k = k + n;
    print();
}

void chessMove(int n)
{
    k = 2 * n;

    if(n == 4)
    {
        move(-5);
        move(4);
        move(-6);
        move(5);
        move(-6);
    }else{
        move(-n-1);
        move(n-1);
        chessMove(n-1);
    }
}

void init()
{
    int i = 0, j = 2*N - 1;
    while(i<j)
    {
        arr[i++] = 'o';
        arr[j--] = '*';
    }

    arr[2 * N] = '-';
    arr[2 * N + 1] = '-';
}

int main()
{
    cin >> N;
    init();
    print();
    chessMove(N);

    return 0;
}