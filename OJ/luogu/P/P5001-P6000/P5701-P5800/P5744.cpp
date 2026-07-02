#include <iostream>
#include <string>
using namespace std;

struct Stu
{
    string name;
    int age;
    int score;
};

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        Stu *stu = new Stu();
        int score;
        cin >> stu->name >> stu->age >> score;
        score = score * 1.2 < 600 ? score * 1.2 : 600;
        stu->score = score;
        stu->age++;
        cout << stu->name << ' ' << stu->age << ' ' << stu->score << '\n';
        delete stu;
    }

    return 0;
}