class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!= t.size())
           return false;

      int freq[26]={};
    

      for(char i:s){
        freq[i-'a']++;
      }

     for(char i:t){
        freq[i-'a']--;
      }
      for(int count:freq){
        if(count!= 0) return false;
      }

        return true;
    }
};
