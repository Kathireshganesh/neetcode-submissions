class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!= t.size())
           return false;

      unordered_map<char,int> m1;
      unordered_map<char,int> m2;

      for(char i:s){
        m1[i]++;
      }

     for(char i:t){
        m2[i]++;
      }


        return m1==m2;
    }
};
