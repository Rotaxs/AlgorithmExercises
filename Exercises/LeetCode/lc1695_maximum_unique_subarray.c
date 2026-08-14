#define max(a, b) ((a) > (b) ? (a) : (b))

int maximumUniqueSubarray(int* nums, int numsSize) {
    int lastSeen[10005];
    memset(lastSeen, -1, sizeof lastSeen);
    int sum = 0;
    int ans = 0;
    for (int l = 0, r = 0; r < numsSize; ++r) {
        sum += nums[r];
        while (l <= r && lastSeen[nums[r]] >= l) {
            sum -= nums[l++];
        }
        lastSeen[nums[r]] = r;
        ans = max(ans, sum);
    }
    return ans;
}