class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& arr) {
        
       
       int x1 = arr[0][0], y1 = arr[0][1];
       int x2 = arr[1][0], y2 = arr[1][1];

        int dx = x2 - x1;
        int dy = y2 - y1;

        for(int i=0; i<arr.size(); i++) {

            int x = arr[i][0];
            int y = arr[i][1];
        
            if((y - y1) * dx != (x - x1) * dy)
            return false;
        }

        return true;
    }
};