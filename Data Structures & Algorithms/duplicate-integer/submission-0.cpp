class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1) return false;
        sort(nums.begin(),nums.end());

        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]) return true;
        }
        return false;
    }
};