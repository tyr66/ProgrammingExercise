#include<iostream>
#include<string>

using namespace std;

//
//注意最终的结果要用long long类型来进行存储，否则有可能会溢出
//

int arr_a[100001];
int arr_tmp[100001];

void merge(int*arr,int len,int lo,int mid,int hi)
{
    if(lo ==mid&&mid == hi)
        return;

    if(hi>len)
        return;

    int i = lo,j = mid;
    int k = 0;

    while(i<mid||j<=hi)
    {
        if(i>=mid)
            arr_tmp[k++] = arr[j++];
        else if(j>hi)
            arr_tmp[k++] = arr[i++];
        else if(arr[i]>arr[j])
            arr_tmp[k++] = arr[j++];
        else
            arr_tmp[k++] = arr[i++];
    }

    for (int i = 0; i < k;i++)
    {
        arr[lo+i] = arr_tmp[i];
    }

}

long long count(int*arr,int len,int lo,int mid,int hi)
{
    if(lo ==mid&&mid == hi)
        return 0;

    if(hi>len)
        return 0;

    long long res = 0;

    for (int i = mid-1,j = hi; i >=lo;i--)
    {
        for (; j >= mid;j--)
        {
            if(arr[i]>arr[j])
            {
                //找到逆序对
                res += (j - mid+1);
                break;
            }
        }
    }

    return res;
}

int main()
{

    int N;
    cin >> N;

    for (int i = 0; i < N;i++)
        cin >> arr_a[i];

    int n = 1;
    long long res = 0;

    for (;n<=N;n*=2)
    {
        for (int i = 0; i < N;i+=2*n)
        {
            int lo = i;
            int mid = min(lo + n,N-1);
            int hi = min(lo+2*n-1,N-1);


            res += count(arr_a,N,lo,mid,hi);
            

            merge(arr_a,N,lo,mid,hi);

        }

        //cout << res << endl;
    }

    /*  for (int i = 0; i < N;i++)
        cout << arr_a[i]<<" "; */
    //cout << endl;

    printf("%lld\n",res);

    return 0;
}