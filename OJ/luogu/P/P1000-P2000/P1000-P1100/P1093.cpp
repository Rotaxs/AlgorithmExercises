#include <iostream>
#include <algorithm>
using namespace std;

const int N = 310;
int n;

struct Stu
{
    int id;
    int chinese;
    int math;
    int english;
    int total;
} stu[N];

bool cmp(Stu stu01, Stu stu02)
{
    if (stu01.total != stu02.total)
        return stu01.total > stu02.total;
    if (stu01.chinese != stu02.chinese)
        return stu01.chinese > stu02.chinese;
    return stu01.id < stu02.id;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        stu[i].id = i;
        cin >> stu[i].chinese >> stu[i].math >> stu[i].english;
        stu[i].total = stu[i].chinese + stu[i].math + stu[i].english;
    }
    sort(stu + 1, stu + n + 1, cmp);
    for (int i = 1; i <= 5; i++)
        cout << stu[i].id << ' ' << stu[i].total << '\n';
    return 0;
}