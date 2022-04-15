#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*

  首先能明确的是，如果过河能够两个人一起过，那就两个人一起过，因为一个人过的话太耽误时间了；回来一定是一个人回来，这个很明显。然后进行讨论：

1个人的情况
  我们首先考虑一个人的情况，很简单，就是自己一个人坐船过河就行，也就是 a[0]。

2个人的情况
  两个人也很简单，两个一起过河，时间是慢的人的时间，也就是如果是升序数组，就是 a[1]。

3个人的情况
  A、B、C 三个人的话，排序变成耗时 A <= B <= C，也就是 A 是最快的，那么最快过河的方案一定是 A 和 （B or C）一起过，然后 A 回来，再陪另一个人过，这样时间就是 A + B + C，也就是 a[0] + a[1] + a[2]。

n个人的情况（n > 3）
  大于三个人的话，我们按 A、B、C、D 四个人讨论（其中 A <= B <= C <= D），每次将最慢得到两个人送过河，有两种情况：
1、最快的人送最慢的两个人过河

A 和 D 过河，耗时 D；
A 回来，耗时 A；
A 和 C 过河，耗时 C；
A 回来，耗时 A。

  四步后总人数就减少 2，耗时 2 * A + C + D。这种方案其实就是 A、C、D 三个人过河的情况，不过最后船要回来。
2、最快的两个人送最慢的两个人过河

A 和 B 过河，耗时 B；
A 回来，耗时 A；
C 和 D 过河，耗时 D；
B 回来，耗时B。

  这四步后总人数同样减小 2，耗时 A + 2 * B + D。

  上边为什么说是最慢，因为总人数 > 4 的时候是一次一次按四个人算的，每次送过去最慢的两个人，相当于每次送 a[n] 和 a[n - 1]，然后 n -= 2。上边两种方案其实看得就是 A + C 和 2 * B 的大小
*/

int main()
{
    int n;
    vector<int> arr;
    cin >> n;

    while(n>0)
    {
        int k;
        cin >> k;

        int val;
        for (int i = 0; i < k;i++)
        {
            cin >> val;
            arr.push_back(val);
        }
        sort(arr.begin(),arr.end());

        int ans = 0;
        while(k>3)
        {
            ans += min(arr[0]+2*arr[1]+arr[k-1],2*arr[0]+arr[k-2]+arr[k-1]);
            k -= 2;
        }

        if(k ==3)
            ans += arr[2] + arr[0]+arr[1];
        else if(k==2)
            ans += arr[1];
        else
            ans += arr[0];

        cout << ans<<endl;

        arr.clear();
        n--;
    }
}