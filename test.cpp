#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> lastSeen;
        int ans = 0;
        for (int l = 0, r = 0; r < n; ++r) {
            if (lastSeen.count(s[r])) {
                l = max(l, lastSeen[s[r]] + 1);
            }
            lastSeen[s[r]] = r;
            ans = max(ans, r - l + 1);
        }
        return ans;
    }
};