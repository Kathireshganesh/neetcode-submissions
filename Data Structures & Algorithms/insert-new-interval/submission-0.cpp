class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;

        for(auto current:intervals){

            if(current[1]<newInterval[0]){
                ans.push_back(current);
            }
            else if(current[0]>newInterval[1]){
                ans.push_back(newInterval);
                newInterval=current;
            }
            else{
               newInterval[0]=min(current[0],newInterval[0]);
               newInterval[1]=max(current[1],newInterval[1]);
            }
           
          
        }
         ans.push_back(newInterval);
          return ans;
    }
};
