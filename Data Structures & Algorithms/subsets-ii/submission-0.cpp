class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int s,vector<int>& nums,vector<int>& path){

        ans.push_back(path);

        for(int i=s;i<nums.size();i++){

            if(i>s && nums[i] == nums[i-1])
               continue;

            path.push_back(nums[i]);

            backtrack(i+1,nums,path);

            path.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> path;

        backtrack(0,nums,path);

        return ans;
    }
};
