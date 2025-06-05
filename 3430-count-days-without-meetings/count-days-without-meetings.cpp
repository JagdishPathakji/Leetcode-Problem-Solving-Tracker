class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        if(meetings.empty()) return 0;

        vector<vector<int>> mergedintervals;
        sort(meetings.begin(),meetings.end());

        mergedintervals.push_back(meetings[0]);
        for(int i=1; i<meetings.size(); i++) {
            if(mergedintervals.back()[1] >= meetings[i][0]) {
                mergedintervals.back()[1] = max(mergedintervals.back()[1],meetings[i][1]);
            }
            else {
                mergedintervals.push_back(meetings[i]);
            }
        }

        int count = 0;
        count += mergedintervals[0][0]-1;

        for(int i=0; i<mergedintervals.size()-1; i++) {
            count += (mergedintervals[i+1][0]-mergedintervals[i][1]-1);
        }

        count += days-mergedintervals.back()[1];

        return count;

    }
};