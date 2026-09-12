class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;

        for(auto inter:intervals){
            if(ans.empty() || inter[0]>ans.back()[1]){
                ans.push_back(inter);
            }
            else{
                ans.back()[1]=max(inter[1],ans.back()[1]);
            }
        }
        return ans;
    }
};
