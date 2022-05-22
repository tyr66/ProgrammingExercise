#include <iostream>
#include <math.h>
using namespace std;

/**
 * 思路：深搜+前缀树
 * 思路是对的，但还是超时了
 */

struct Node
{
    int val;
    int next[10];
};

int sum;
int mat[6][6];
bool flag = false;
bool prefix[100000]; //前缀
bool suffix[100000]; //后缀
int number_map[100000];
int row[6], col[6];
int main_diagonal;
int sub_diagonal;
int multer[6] = {0, 1, 10, 100, 1000, 10000};

void print_mat()
{
    flag = true;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cout << mat[i][j];
        }
        cout << endl;
    }

    cout << endl;
}
//生成素数哈希表
void generate_map()
{
    number_map[0] = 1;
    number_map[1] = 1;
    number_map[3] = 0;

    for (int i = 2; i <= 100000; i++)
    {
        if (number_map[i] == 1)
            continue;
        int j = 2;
        int v = i;
        while (v * j <= 100000)
        {
            number_map[v * j] = 1; //设置为非质数
            j++;
        }
    }
}

void build_Trie(int sum)
{
    int number[5];
    for (int i = 10000; i < 100000; i++)
    {
        if (number_map[i])
        {
            number_map[i] = 0;
            continue;
        }

        number[0] = i / 10000;
        number[1] = (i / 1000) % 10;
        number[2] = (i / 100) % 10;
        number[3] = (i / 10) % 10;
        number[4] = i % 10;

        int sum_number = 0;

        for (int j = 0; j < 5; j++)
            sum_number += number[j];
        if (sum_number != sum)
            continue;

        number_map[i] = 1;
        prefix[i / 10000] = prefix[i / 1000] = prefix[i / 100] = prefix[i / 10] = prefix[i] = true;
        suffix[i] = suffix[i % 10] = suffix[i % 100] = suffix[i % 1000] = suffix[i % 10000] = true;
    }
}

int get_remain(int v)
{
    int s = 0;
    for (int i = 1; i < 5; i++)
    {
        s += v % 10;
        v /= 10;
    }

    return sum - s;
}

void dfs(int n)
{
    int r = (n / 5) + 1;
    int c = (n % 5) + 1;

    if (n == 25)
    {
        print_mat();
        return;
    }

    int i = r == 1 || c == 1 ? 1 : 0;
    if (r == 5 || c == 5)
    {
        i = r == 5 ? get_remain(col[c]) : get_remain(row[r]);
        row[r] = row[r] * 10 + i;
        col[c] = col[c] * 10 + i;
        if (r == c)
            main_diagonal = main_diagonal * 10 + i;
        if (r + c == 6)
            sub_diagonal = i * multer[r] + sub_diagonal;

        bool check_row_and_col = prefix[row[r]] && prefix[col[c]];
        bool check_main_diagonal = r != c || prefix[main_diagonal];
        bool check_sub_diagonal = r + c != 6 || suffix[sub_diagonal];

        //print_mat();
        if (check_row_and_col && check_main_diagonal && check_sub_diagonal)
        {
            mat[r][c] = i;
            dfs(n + 1);
        }

        row[r] = row[r] / 10;
        col[c] = col[c] / 10;
        if (r == c)
            main_diagonal = main_diagonal / 10;
        if (r + c == 6)
            sub_diagonal = sub_diagonal % multer[r];
        return;
    }

    for (i; i < 10; i++)
    {
        row[r] = row[r] * 10 + i;
        col[c] = col[c] * 10 + i;
        if (r == c)
            main_diagonal = main_diagonal * 10 + i;
        if (r + c == 6)
            sub_diagonal = i * multer[r] + sub_diagonal;

        bool check_row_and_col = prefix[row[r]] && prefix[col[c]];
        bool check_main_diagonal = r != c || prefix[main_diagonal];
        bool check_sub_diagonal = r + c != 6 || suffix[sub_diagonal];

        if (check_row_and_col && check_main_diagonal && check_sub_diagonal)
        {
            mat[r][c] = i;
            dfs(n + 1);
        }

        row[r] = row[r] / 10;
        col[c] = col[c] / 10;
        if (r == c)
            main_diagonal = main_diagonal / 10;
        if (r + c == 6)
            sub_diagonal = sub_diagonal % multer[r];
    }
}

int main()
{
    cin >> sum;
    cin >> mat[1][1];
    row[1] = mat[1][1];
    col[1] = mat[1][1];
    main_diagonal = mat[1][1];
    generate_map();
    build_Trie(sum);

    dfs(1);

    if (!flag)
    {
        cout << "NONE" << endl;
    }

    return 0;
}