class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxp=nums[0];
        int minp=nums[0];

        int ans=nums[0];

        for(int i=1;i<nums.size();i++){
            int x=nums[i];

            int oldMax=maxp;
            int oldMin=minp;

            maxp=max({x,x*oldMax,x*oldMin});

            minp=min({x,x*oldMax,x*oldMin});

            ans=max(ans,maxp);

        }
        return ans;
    }
};
