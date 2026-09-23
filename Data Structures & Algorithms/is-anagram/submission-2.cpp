class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!= t.size())
           return false;

      unordered_map<char,int> m1;
    

      for(char i:s){
        m1[i]++;
      }

     for(char i:t){
        m1[i]--;
      }
      for(auto [ch,count]:m1){
        if(count!= 0) return false;
      }

        return true;
    }
};
