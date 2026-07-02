#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int N;
string res, path;
vector<string> words;
vector<int> st;
int ans = 0;

// 不重合或存在包含关系，返回 0
int get_overlap(string w1, string w2)
{
    int len1 = w1.length(), len2 = w2.length();
    // 循环 i 代表重合部分的长度
    // 注意：i 必须小于两个单词的最小长度，否则会形成包含关系
    for (int i = 1; i < min(len1, len2); i++)
    {
        if (w1.substr(len1 - i) == w2.substr(0, i))
            return i;
    }
    return 0;
}

void dfs()
{
    // cout << path << " " << path.length() << '\n';
    ans = max(ans, (int)path.length());
    for (int i = 0; i < N; i++)
    {
        string cur_word = words[i];
        int overlap = get_overlap(path, cur_word);
        if (overlap != 0 && st[i] < 2)
        {
            st[i]++;
            string tmp = path;
            path += cur_word.substr(overlap);
            dfs();
            path = tmp;
            st[i]--;
        }
    }
}

int main()
{
    cin >> N;
    char head;
    words.resize(N);
    st.resize(N, 0);
    for (int i = 0; i <= N; i++)
    {
        if (i == N)
        {
            cin >> head;
            continue;
        }
        cin >> words[i];
    }
    for (int i = 0; i < N; i++)
    {
        if (words[i][0] == head)
        {
            path = words[i];
            st[i]++;
            dfs();
            st[i]--;
        }
    }
    cout << ans << '\n';
    return 0;
}