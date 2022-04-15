#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

/**
 * 思路：将字符串数组strs按字典序进行排序，定义对于两个字符串s1,s2,两个字符串的差异度d = strs[i].size() - idx，其中 idx 
 * 为s1，s2 从0开始strs[i-1][idx]!=strs[i][idx]刚好不相等时的字符的下标。差异度d表示两个字符串的差异程度。对于已经按
 * 字典序排序了的字符串数组strs，相邻两个字符串s1,s2计算差异度的对比过程和将s2插入单词查找树中的对比过程一致，差异度d为
 * 需要插入到单词查找树种的最小节点数。
 */

int main()
{
    vector<string> strs;
    string tmp;

    while(cin>>tmp)
    {
        strs.push_back(tmp);
    }

    sort(strs.begin(),strs.end());

    int count = strs[0].size();

    for (int i = 1; i < strs.size();i++)
    {
        int idx = 0;
        int minLen = min(strs[i].size(),strs[i-1].size());

        while(idx<minLen&&strs[i-1][idx] == strs[i][idx])
            idx++;

        count += strs[i].size() - idx;
    }

    cout << count+1<<endl;//还有一个根节点

    return 0;
}