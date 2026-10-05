class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int s,vector<int>& nums,vector<int>& path){

        ans.push_back(path);

        for(int i=s;i<nums.size();i++){
              path.push_back(nums[i]);

              backtrack(i+1,nums,path);

              path.pop_back();

        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        backtrack(0,nums,path);
        return ans;
    }
};
