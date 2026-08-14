#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
using namespace std;


class Solution
{
public:
    map<char, int> to_map(string &s)
    {
        map<char, int> smap;
        for (char &c : s) smap[c]++;
        return smap;
    }

    int minStickers(vector<string> &stickers, string target)
    {
        int ans = -1;
        map<char, int> tmap = to_map(target);
        

        return ans;
    }

};

int main()
{
}
