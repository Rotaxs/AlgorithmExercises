#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 将职位转为数字，方便比较
int getPos(string s)
{
    if (s == "BangZhu")
        return 0;
    if (s == "FuBangZhu")
        return 1;
    if (s == "HuFa")
        return 2;
    if (s == "ZhangLao")
        return 3;
    if (s == "TangZhu")
        return 4;
    if (s == "JingYing")
        return 5;
    return 6; // BangZhong
}

string getPosName(int p)
{
    string names[] = {"BangZhu", "FuBangZhu", "HuFa", "ZhangLao", "TangZhu", "JingYing", "BangZhong"};
    return names[p];
}

struct Member
{
    string name;
    int pos;
    long long gong;
    int level;
    int id;
};

bool cmpGong(Member a, Member b)
{
    if (a.gong != b.gong)
        return a.gong > b.gong;
    return a.id < b.id;
}

bool cmpFinal(Member a, Member b)
{
    if (a.pos != b.pos)
        return a.pos < b.pos;
    if (a.level != b.level)
        return a.level > b.level;
    return a.id < b.id;
}

int main()
{
    int n;
    cin >> n;
    vector<Member> leaders, members;

    for (int i = 0; i < n; i++)
    {
        string name, posStr;
        long long gong;
        int level;
        cin >> name >> posStr >> gong >> level;
        Member m = {name, getPos(posStr), gong, level, i};

        // 帮主和副帮主不参与重新分配职位
        if (m.pos <= 1)
            leaders.push_back(m);
        else
            members.push_back(m);
    }

    // 对成员按帮贡排序，决定新职位
    sort(members.begin(), members.end(), cmpGong);

    // 重新分配职位
    for (int i = 0; i < members.size(); i++)
    {
        if (i < 2)
            members[i].pos = 2; // 护法
        else if (i < 6)
            members[i].pos = 3; // 长老
        else if (i < 13)
            members[i].pos = 4; // 堂主
        else if (i < 38)
            members[i].pos = 5; // 精英
        else
            members[i].pos = 6; // 帮众
    }

    // 合并所有成员，进行最终排序
    vector<Member> all = leaders;
    all.insert(all.end(), members.begin(), members.end());
    sort(all.begin(), all.end(), cmpFinal);

    // 输出
    for (const auto &m : all)
    {
        cout << m.name << " " << getPosName(m.pos) << " " << m.level << endl;
    }

    return 0;
}