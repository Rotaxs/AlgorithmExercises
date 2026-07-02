#include <iostream>
using namespace std;

const int N = 1010;
int stus[N];

struct Stu
{
    int id;
    int study_score;
    int extended_score;
};

bool is_excellent(struct Stu stu)
{
    bool flag1 = (stu.study_score + stu.extended_score > 140);
    bool flag2 = stu.study_score * 7 + stu.extended_score * 3 >= 800;
    return flag1 & flag2;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        struct Stu stu;
        cin >> stu.id >> stu.study_score >> stu.extended_score;
        if (is_excellent(stu))
            cout << "Excellent" << '\n';
        else
            cout << "Not excellent" << '\n';
    }
    return 0;
}