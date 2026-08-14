#include <iostream>
#include <string>
using namespace std;

const int N = 1e6 + 10;
int n, m;

struct Toy
{
    short dir;
    string job;
} toys[N];

struct Commands
{
    short dir;
    int s;
} com[N];

// -1表示顺时针
short get_true_dir(short p_dir, short c_dir)
{
    if (!(p_dir ^ c_dir))
        return -1;
    return 1;
}

// s正表示逆时针
int get_true_pos(int pos, int s)
{
    if (pos + s >= 0)
        return (pos + s) % n;
    return n + (pos + s) % n;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> toys[i].dir >> toys[i].job;
    for (int i = 0; i < m; i++)
        scanf("%hd %d", &com[i].dir, &com[i].s);
    int pos = 0;
    for (int i = 0; i < m; i++)
    {
        pos = get_true_pos(pos, get_true_dir(toys[pos].dir, com[i].dir) * com[i].s);
    }
    cout << toys[pos].job << endl;
}
