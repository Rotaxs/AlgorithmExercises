#include <bits/stdc++.h>
using namespace std;

const int N = 5e4 + 10;
unordered_map<string, int> id;
int cnt = 0;
string id_to_string[N];
int fa[N];

int get_id(string s)
{
    if (id.find(s) == id.end())
    {
        id[s] = cnt++;
        fa[id[s]] = id[s];
        id_to_string[id[s]] = s;
    }
    return id[s];
}

int find(int x)
{
    if (fa[x] == x) return x;
    return fa[x] = find(fa[x]);
}

void solve()
{
    string f, c;
    char ch;
    while (cin >> ch && ch != '$')
    {
        if (ch == '#')
        {
            cin >> f;
        }
        else if (ch == '+')
        {
            cin >> c;
            fa[get_id(c)] = get_id(f);
        }
        else if (ch == '?')
        {
            cin >> c;
            cout << c << ' ' << id_to_string[find(get_id(c))] << '\n';
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;

// const int N = 5 * 1e4 + 10;

// map<string, string> fa;

// string find(string name)
// {
//     if (fa[name] == "" || fa[name] == name) return name;
//     return fa[name] = find(fa[name]);
// }

// void solve()
// {
//     string f, c;
//     char ch;
//     while (cin >> ch && ch != '$')
//     {
//         if (ch == '#')
//         {
//             cin >> f;
//             if (fa[f] == "") fa[f] = f;
//         }
//         else if (ch == '+')
//         {
//             cin >> c;
//             fa[c] = f;
//         }
//         else if (ch == '?')
//         {
//             cin >> c;
//             cout << c << ' ' << find(c) << '\n';
//         }
//     }
// }

// int main()
// {
//     ios_base::sync_with_stdio(0);
//     cin.tie(0);
    
//     // int t;
//     // cin >> t;
//     // while (t--) solve();

//     solve();
    
//     return 0;
// }