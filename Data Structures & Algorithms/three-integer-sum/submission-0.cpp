class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n=nums.size();

        for(int i=0;i<n;i++){
            unordered_set<int> seen;

            for(int j=i+1;j<n;j++){
                int need = -nums[i]-nums[j];
                if(seen.count(need)){

                    vector<int> triplet = {
                        nums[i],
                        need,
                        nums[j]
                    };

                    sort(triplet.begin(), triplet.end());
                    ans.push_back(triplet);
                }
                seen.insert(nums[j]);
            }
        }
        sort(ans.begin(),ans.end());
        ans.erase(unique(ans.begin(),ans.end()),ans.end());

        return ans;
    }
};
