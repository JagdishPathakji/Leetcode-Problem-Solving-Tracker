class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();

        int start = 0;
        int end = rows * cols - 1;

        while(start <= end) {

            int mid = start + (end - start)/2;
            int indexrow = mid / cols;
            int indexcol = mid % cols;

            if(matrix[indexrow][indexcol] == target)
            return true;
            else if(matrix[indexrow][indexcol] < target)
            start = mid + 1;
            else
            end = mid - 1;
        } 

        return false;
    }
};