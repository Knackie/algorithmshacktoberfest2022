class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int l = nums.size();
        if (nums.empty()) return 0;
        vector<int> d(l, -1);
        int ans = 0;
        d[0] = 0;
        for (int i = 1 ; i < l ; i++) {
            if (nums[i] > nums[d[ans]]) {
                ans++;
                d[ans] = i;
            } else if (nums[i] <= nums[d[0]]) {
                d[0] = i;
            } else {
                int l = 0;
                int r = ans;
                while ((r - l) > 1) {
                    int m = l + (r - l) / 2;
                    if (nums[i] <= nums[d[m]]) {
                        r = m;
                    } else {
                        l = m;
                    }
                }
                d[r] = i;
            }
        }
        return ans + 1;
    }
};