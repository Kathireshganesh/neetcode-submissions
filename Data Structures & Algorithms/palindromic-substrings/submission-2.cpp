class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        vector<vector<int>> dp(n,vector<int>(n,false));
        int count=0;

        for(int i=0;i<n;i++){
            dp[i][i]=true;
            count++;
        }

        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){

              int  j=i+len-1;

                if(s[i]==s[j]){
                    if(len==2){
                        dp[i][j]=true;
                    

                    }
                    else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                if(dp[i][j]){
                    count++;
                }
            }
        }
        return count;
    }
};
