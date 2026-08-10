#include <string.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int lengthOfLongestSubstring(char* s) {
    int n = strlen(s);
    int lastSeen[128];
    memset(lastSeen, -1, sizeof lastSeen);
    int ans = 0;
    for (int l = 0, r = 0; r < n; ++r) {
        if (lastSeen[s[r]] != -1) {
            l = max(l, lastSeen[s[r]] + 1);
        }
        lastSeen[s[r]] = r;
        ans = max(ans, r - l + 1);
    }
    return ans;
}   