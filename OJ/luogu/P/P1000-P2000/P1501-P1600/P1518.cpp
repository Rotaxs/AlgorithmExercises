#include <iostream>
#include <vector>
#include <utility>
#include <tuple>
#include <map>
using namespace std;

/*

*...*.....
......*...
...*...*..
..........
...*.F....
*.....*...
...*......
..C......*
...*.*....
.*.*......

*/

// 此题难点在于如何判断永远无法相遇
// 可以用一个映射哈希表存储农民和牛的所有状态，若有相同的状态产生，说明进入了循环
// 也可以村换一个较大的数值，如 200？，超过这个移动次数时输出 0

vector<vector<char>> gmap(12, vector<char>(12));

pair<pair<int, int>, pair<int, int>> init_map(vector<vector<char>> &gmap)
{
    for (int i = 0; i < 12; i++)
    {
        gmap[0][i] = '*';
        gmap[11][i] = '*';
        gmap[i][0] = '*';
        gmap[i][11] = '*';
    }

    pair<pair<int, int>, pair<int, int>> ret;

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            cin >> gmap[i][j];
            if (gmap[i][j] == 'F')
            {
                ret.first.first = i;
                ret.first.second = j;
            }
            if (gmap[i][j] == 'C')
            {
                ret.second.first = i;
                ret.second.second = j;
            }
        }
    }

    return ret;
}

void print_map(vector<vector<char>> &gmap)
{
    for (int i = 0; i < 12; i++)
    {
        for (int j = 0; j < 12; j++)
            cout << gmap[i][j];
        cout << "\n";
    }
}

void rotate(pair<int, int> &dir)
{
    int tmp;
    tmp = dir.first;
    dir.first = dir.second;
    dir.second = -tmp;
}

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    pair<pair<int, int>, pair<int, int>> pos = init_map(gmap);
    map<tuple<int, int, int, int, int, int, int, int>, int> passeds;
    int fr = pos.first.first, fc = pos.first.second;
    int cr = pos.second.first, cc = pos.second.second;
    // print_map(gmap);

    // {-1, 0} 表示往北
    pair<int, int> cDir = {-1, 0}, fDir = {-1, 0};
    int m;
    for (m = 0;; m++)
    {
        if (fr == cr && fc == cc)
            break;
        auto passed = make_tuple(fr, fc, fDir.first, fDir.second, cr, cc, cDir.first, cDir.second);
        if (passeds.count(passed))
        {
            // m = 0;
            // break;
            cout << 0 << endl;
            return 0;
        }
        passeds[passed] = 1;
        if (gmap[fr + fDir.first][fc + fDir.second] == '*')
            rotate(fDir);
        else
        {
            fr += fDir.first;
            fc += fDir.second;
        }
        if (gmap[cr + cDir.first][cc + cDir.second] == '*')
            rotate(cDir);
        else
        {
            cr += cDir.first;
            cc += cDir.second;
        }
    }
    cout << m << endl;

    return 0;
}