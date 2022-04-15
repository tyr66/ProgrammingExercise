#include<iostream>
#include<string>
using namespace std;


/**
 * 思路：在中序遍历字符串s1中第一个出现在层序遍历字符串s2 中的字符为根节点记此时s1中下标为idx，由此根节点可以判断其左子树和右子树
 * 分别为[l,idx-1]和[idx+1,r] ，同样对于其左右子树第一个出现在层序遍历中的节点分别为左右子树的根节点，由此可以看出我们在递归的每一层都可以
 * 根据中序遍历和层序遍历来判断出当前树的根节点和其对应的左右子树的范围。
 */


string levelOrd;
string midOrd;

void travel(int l,int r)
{
    //printf("l = %d, r = %d\n",l,r);

    if(l==r)
    {
        cout << midOrd[l];
        return;
    }

    int idx;
    bool flag = false;
    for (int i = 0; i < levelOrd.size();i++)
    {
        for (int j = l; j <= r;j++)
        {
            //找节点中第一个出现在LevelOrd的节点的下标
            if(levelOrd[i] == midOrd[j])
            {
                idx = j;
                flag = true;
                break;
            }
        }

        if(flag)
        {
            break;
        }
    }

    cout << midOrd[idx];

    if(idx-1>=l)
        travel(l,idx-1);
    
    if(idx+1<=r)
        travel(idx+1,r);
}

int main()
{
    cin >> midOrd >> levelOrd;

    travel(0,midOrd.size()-1);

    return 0;
}