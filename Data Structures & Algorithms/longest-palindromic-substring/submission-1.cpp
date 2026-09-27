class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();

        vector<vector<bool>> dp(n,vector<bool>(n,false));

        int start=0;
        int maxlen=1;

        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }

        for(int len=2;len<=n;len++){
            for(int i=0;i+len-1<n;i++){

                int j=i+len-1;

                if(s[i]==s[j]){
                    if(len==2){
                        dp[i][j]=true;
                    }
                    else{
                        dp[i][j]=dp[i+1][j-1];
                    }
                }
                if(dp[i][j] &&len>maxlen){
                    start=i;
                    maxlen=len;
                }
            }
        }

        return s.substr(start,maxlen);
    }
};
