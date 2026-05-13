class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        
        int arrows = 0;
        sort(points.begin(),points.end());

        for(int i=0; i<points.size(); i++) {

            int start = points[i][0];
            int end = points[i][1];

            while(i+1 < points.size() && points[i+1][0] >= start && points[i+1][0] <= end) {
                
                start = max(start,points[i+1][0]);
                end = min(end,points[i+1][1]);
                i++;
            }

            arrows++;
        }

        return arrows;
    }
};