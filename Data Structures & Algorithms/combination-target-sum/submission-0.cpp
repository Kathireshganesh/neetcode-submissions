class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int s,vector<int>& nums,int target,vector<int>& path){
        if(target==0){
            ans.push_back(path);
            return;
        }

        if(target<0) return;

        for(int i=s;i<nums.size();i++){
         
          path.push_back(nums[i]);

          backtrack(i,nums,target-nums[i],path);

          path.pop_back();

        }

    }

    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> path;
        backtrack(0,nums,target,path);
        return ans;
    }
};
