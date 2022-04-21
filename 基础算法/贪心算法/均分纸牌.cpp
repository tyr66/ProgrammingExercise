#include<iostream>
#include<vector>

using namespace std;

/**
 * 思路：
 *  如果你想到把每堆牌的张数减去平均张数，题目就变成移动正数，加到负数中，使大家都变成 0，那就意味着成功了—半。
    拿例题来说，平均张数为 10，原张数 9，8，17，6，变为 -1，-2，7，-4，从左边出发：要使第 1 堆的牌数 -1 变为 0，
    只需将 -1 张牌移到它的右边（第 2 堆）-2 中;结果是 -1 变为 0，-2 变为 -3，各堆牌张数变为 0，-3， 7，-4；同理，继续......
 * 
 */

int arr[101];

int main()
{
    int n;
    cin >> n;
    int sum = 0;

    for (int i = 1; i <= n;i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }

    int count = 0;
    int average = sum / n;
    

    for (int i = 1; i <= n;i++)
    {
        arr[i] -= average;
        arr[i] += arr[i-1];

        if(arr[i]!=0)
        {
            count++;
        }
    }

    cout << count<<endl;

    return 0;
}