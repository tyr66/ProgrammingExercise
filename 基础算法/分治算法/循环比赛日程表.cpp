#include <iostream>
using namespace std;


/**
 * 思路：分治思想，关键是观察问题，通过将文件规模缩小来解决问题 
 * 从八位选手的循环比赛表中可以看出，这是一个具有对称性的方阵，可以把方阵一分为四来看，那么左上角的 4×4 的方阵就是前四位选手的循环比赛表，
 * 而右上角的 4*4 的方阵就是后四位选手的循环比赛表，它们在本质上是一样的，都是4 个选手的循环比赛表，所不同的只是选手编号不同而已，将左上
 * 角中方阵的所有元素加上 4 就能得到右上角的方阵。下方的两个方阵表示前四位选手和后四位选手进行交义循环比赛的情况，同样具有对称性，将右上
 * 角方阵复制到左下角即得到1、2、3、4 四位选手和 5、6、7、8 四位选手的循环比赛表，根据对称性，右下角的方阵应与左上角的方阵相同。这样，八
 * 名选手的循环比赛表可以由四名选手的循环比赛表根据对称性生成出来.同样地，四名选手的循环比赛表可以由二名选手的循环比赛表根据对称性生成出来，
 * 而两名选手的循环比赛表可以说是已知的，这种程序设计方法叫做分治法，其基本思想是把一个规模为 n 的问题分成若干个规模较小的问题，使得从这些
 * 较小问题的解易于构造出整个问题的解。
   程序中用数组 matchlist 记录 n 名选手的循环比赛表，整个循环比赛表从最初的 1*1的方阵按上述规则生成出2*2 的方阵，再生成出 4*4 的方阵，…，
   直到生成出整个循环比赛表为止。变量half表示当前方阵的大小，也是要生成的下—个方阵的大小的一半。
 * 
 */

int mat[10240][10240];




int main()
{
    int m;
    cin >> m;

    int k = 1;
    int dist = 1;
    mat[0][0] = 1;

    while (k <= m)
    {
        int r = 0, c = 0;
        int _r = 0, _c = c + dist;

        for (int i = 0; i < dist; i++)
        {
            for (int j = 0; j < dist; j++)
            {
                mat[_r + i][_c + j] = mat[r + i][c + j] + dist;
            }
        }

        r = _r;
        c = _c;

        _r = dist;
        _c = 0;

        for (int i = 0; i < dist; i++)
        {
            for (int j = 0; j < dist; j++)
            {
                mat[_r + i][_c + j] = mat[r + i][c + j];
            }
        }

        r = 0;
        c = 0;
        _r = dist;
        _c = dist;

        for (int i = 0; i < dist; i++)
        {
            for (int j = 0; j < dist; j++)
            {
                mat[_r + i][_c + j] = mat[r + i][c + j];
            }
        }

        dist *= 2;
        k++;
    }

    //dist /= 2;
    for (int i = 0; i < dist; i++)
        {
            for (int j = 0; j < dist; j++)
            {
                cout << mat[i][j]<<" ";
            }
            cout << endl;
        }

    return 0;
}