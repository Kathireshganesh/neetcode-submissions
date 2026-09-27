class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();

        vector<int> maxDP(n);
        vector<int> minDP(n);

        maxDP[0]=nums[0];
        minDP[0]=nums[0];
int ans=nums[0];
        for(int i=1;i<n;i++){

            int x=nums[i];

            maxDP[i]=max({x,x*maxDP[i-1],x*minDP[i-1]});
            minDP[i]=min({x,x*maxDP[i-1],x*minDP[i-1]});

            ans=max(ans,maxDP[i]);

        }
        return ans;
    }
};
