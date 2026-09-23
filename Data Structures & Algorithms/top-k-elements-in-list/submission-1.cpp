class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> mp;

        for(int i:nums){
             mp[i]++;
        }
        vector<pair<int,int>> p;

        for(auto [num,count]: mp){
            p.push_back({num,count});
        }

        sort(p.begin(),p.end(),
        [] (auto &a,auto &b){
             return a.second > b.second;
        });

        for(int i=0;i<k;i++){
            ans.push_back(p[i].first);
        }
     return ans;
    }
};
