class Solution {
   public:
    int robRange(vector<int>& nums, int l, int r) {
        vector<int> dp(r - l + 1);

        dp[0] = nums[l];

        if (l == r) return dp[0];

        dp[1] = max(nums[l], nums[l + 1]);

        for (int i = 2; i < dp.size(); i++) {
            dp[i] = max(dp[i - 1], nums[l + i] + dp[i - 2]);
        }
        return dp.back();
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];

        return max(robRange(nums, 1, n - 1), robRange(nums, 0, n - 2));
    }
};
