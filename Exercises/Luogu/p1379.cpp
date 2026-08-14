#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

string target = "123804765", start;
unordered_map<string, int> dist;
queue<string> q;
int dr[] = {-1, 0, 1, 0}, dc[] = {0, 1, 0, -1};

int bfs(string start)
{
    if (start == target)
        return 0;

    q.push(start);
    dist[start] = 0;

    while (!q.empty())
    {
        string cur_s = q.front();
        q.pop();

        int cur_zero = cur_s.find('0');
        int cur_r = cur_zero / 3;
        int cur_c = cur_zero % 3;

        for (int i = 0; i < 4; i++)
        {
            int ne_r = cur_r + dr[i];
            int ne_c = cur_c + dc[i];

            if (ne_r < 0 || ne_r >= 3 || ne_c < 0 || ne_c >= 3)
                continue;

            int ne_zero = ne_r * 3 + ne_c;
            string ne_s = cur_s;
            swap(ne_s[cur_zero], ne_s[ne_zero]);

            if (dist.count(ne_s))
                continue;
            dist[ne_s] = dist[cur_s] + 1;
            if (ne_s == target)
                return dist[ne_s];
            q.push(ne_s);
        }
    }
    return -1;
}

int main()
{
    cin >> start;
    cout << bfs(start) << '\n';
    return 0;
}
