class Solution {
public:
   vector<vector<string>> ans;

   bool isPalindrome(string& s,int left,int right){

           while(left<right){

            if(s[left] != s[right])
                return false;

            left++;
            right--;
           }
           return true;

   }

   void backtrack(int start,string& s,vector<string>& path){

      if(start==s.size()){
        ans.push_back(path);
        return;
      }

      for(int end=start;end<s.size();end++){
        if(!isPalindrome(s,start,end))
             continue;
      

      path.push_back(s.substr(start,end-start+1));

      backtrack(end+1,s,path);

      path.pop_back();
   }
   }
    vector<vector<string>> partition(string s) {
        vector<string> path;

        backtrack(0,s,path);

        return ans;
    }
   
};
