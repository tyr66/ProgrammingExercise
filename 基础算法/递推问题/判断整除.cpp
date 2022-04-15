#include<iostream>
#include<vector>

using namespace std;

int arr[10000];
bool res[10000][100];

int main()
{

    int n,k;
    cin >> n >> k;

    for (int i = 1; i <= n;i++)
    {
        cin >> arr[i];
        arr[i] %= k;
    }

    res[0][0] = true;

    //动态规划的思想
    for (int i = 1; i <= n;i++)
    {
        for (int j = 0; j < k;j++)
        {
            //将前n-1个数看成一个整体序列，则n个数可能产生的结果就等于“前n-1个数产生的所有结果分别加上第n个数或分别减去第n个数”
            //从前面所有项的值 对k取余后的结果进行考虑,数组res[i][j] 表示前i项 的组合对k取余后结果为j的组合是否存在，res[i][j] = 1 表示存在取余后为j的组合。
            if(res[i-1][j])
            {
                res[i][(j + arr[i]) % k] = true;
                res[i][(abs(j - arr[i])) % k] = true;//防止 j-arr[i] 的结果为负数因此要取其绝对值
            }
        }
    }

    if(res[n][0])
    {
        cout << "YES"<<endl;
    }else{
        cout << "NO"<<endl;
    }

    return 0;
}