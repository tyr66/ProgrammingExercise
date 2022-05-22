#include <iostream>
using namespace std;

/**
 * 思路：深搜+剪枝
 * 这题的剪枝并不难，从测试用例可以看出该题使用贪心策略是不可行的。
 */

struct Rect
{
    int left_y, left_x;
    int right_y, right_x;
    int col;
};

int in_degree[17];
int edge[17][17];
Rect rect[17];
bool isPaint[17];
int N;
int min_count = 0x3f3f3f3f;

void buildTree()
{
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            if (i == j)
                continue;

            if (rect[j].left_y == rect[i].right_y)
            {
                if (rect[i].left_x >= rect[j].left_x && rect[i].left_x < rect[j].right_x)
                {
                    in_degree[j]++;
                    edge[i][j] = 1;
                }
                else if (rect[j].left_x >= rect[i].left_x && rect[j].left_x < rect[i].right_x)
                {
                    in_degree[j]++;
                    edge[i][j] = 1;
                }
            }
        }
    }
}

void cal_min_paintcount(int prev_col, int paint_count, int switch_count)
{
    if (paint_count == N)
    {
        min_count = min(switch_count, min_count);
        return;
    }

    if (switch_count >= min_count)
    {
        return;
    }

    for (int i = 1; i <= N; i++)
    {
        if (!isPaint[i] && in_degree[i] == 0)
        {

            for (int j = 1; j <= N; j++)
            {
                if (edge[i][j] == 1)
                {
                    in_degree[j]--;
                }
            }

            isPaint[i] = true;

            if (prev_col != rect[i].col)
                cal_min_paintcount(rect[i].col, paint_count + 1, switch_count + 1);
            else
                cal_min_paintcount(rect[i].col, paint_count + 1, switch_count);

            isPaint[i] = false;

            for (int j = 1; j <= N; j++)
            {
                if (edge[i][j] == 1)
                {
                    in_degree[j]++;
                }
            }
        }
    }
}

int main()
{
    cin >> N;

    for (int i = 1; i <= N; i++)
    {
        cin >> rect[i].left_y >> rect[i].left_x;
        cin >> rect[i].right_y >> rect[i].right_x;
        cin >> rect[i].col;
    }

    buildTree();

    /* for (int i = 1; i <= N; i++)
    {
        printf("%d = %d\n", i, in_degree[i]);
    } */

    cal_min_paintcount(0, 0, 0);

    cout << min_count << endl;

    return 0;
}