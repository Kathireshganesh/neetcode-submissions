/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> starts;
        vector<int> ends;

        for(auto curr:intervals){
            starts.push_back(curr.start);
            ends.push_back(curr.end);
        }

        sort(starts.begin(),starts.end());
        sort(ends.begin(),ends.end());

        int i=0,j=0,room=0;

        while(i<starts.size()){
            if(starts[i]<ends[j]){
                room++;
                i++;
            }
            else{
                j++;i++;
            }
        }
   return room;
    }
};
