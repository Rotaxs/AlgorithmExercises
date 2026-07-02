#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e6;
int n, m, p;

int fa[N];
int ranks[N];
int ques[N][2];

void init()
{
    for (int i = 0; i < n; i++)
    {
        fa[i] = i;
        ranks[i] = 1;
    }
}

int find(int x)
{
    return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

void unite(int i, int j)
{
    int x = find(i), y = find(j);
    if (x == y)
        return;
    if (ranks[x] < ranks[y])
        swap(x, y);
    fa[y] = x;
    if (ranks[x] == ranks[y])
        ranks[x]++;
}

int main()
{
    cin >> n >> m >> p;
    init();
    int M1, M2;
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &M1, &M2);
        unite(M1, M2);
    }
    // scanf("%d %d", &mems[i][0], &mems[i][0]);
    for (int i = 0; i < p; i++)
        scanf("%d %d", &ques[i][0], &ques[i][1]);

    for (int i = 0; i < p; i++)
    {
        if (find(ques[i][0]) == find(ques[i][1]))
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}