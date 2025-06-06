class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size() == 0) return {};
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> mergedintervals;
        mergedintervals.push_back(intervals[0]);

        for(int i=1; i<intervals.size(); i++) {
            if(mergedintervals.back()[1] >= intervals[i][0]) {
                mergedintervals.back()[1] = max(mergedintervals.back()[1],intervals[i][1]);
            }
            else {
                mergedintervals.push_back(intervals[i]);
            }
        }

        return mergedintervals;
    }
};