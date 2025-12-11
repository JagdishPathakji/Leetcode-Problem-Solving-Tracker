class Solution {
public:

    static bool compare(vector<int> &a, vector<int> &b) {

        if(a[1] > b[1]) {
            return false;           
        }
        else if(a[1] < b[1]) {
            return true;
        }
        else {
            return a[0] < b[0];
        }
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(),intervals.end(), compare);

        pair<int,int> p = {intervals[0][0],intervals[0][1]};

        int count = 0;
        for(int i=1; i<intervals.size(); i++) {
            if(p.first == intervals[i][0] && p.second == intervals[i][1])
            count++;
            else if(p.second > intervals[i][0] && p.second <= intervals[i][1])
            count++;
            else {
                p.first = intervals[i][0];
                p.second = intervals[i][1];
            }
        }

        return count;
    }
};