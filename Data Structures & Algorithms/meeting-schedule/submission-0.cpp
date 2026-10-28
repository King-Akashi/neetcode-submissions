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
    bool canAttendMeetings(vector<Interval>& v) {
        int n = v.size();
        sort(v.begin(), v.end(), [&](Interval a, Interval b){
            if(a.start==b.start)return a.end<b.end;
            return a.start<b.start;
        });
        for(int i = 0;i<n-1;i++){
            if(v[i+1].start<v[i].end){
                return false;
            }
        }
        return true;
    }
};
