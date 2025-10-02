class Solution {
public:
    vector<int> sortedSquares(vector<int>& arr) {
    
        int start = 0;
        int end = arr.size()-1;
        int pos = arr.size()-1;

        vector<int> ans(arr.size());
        while(start <= end) {

            if(abs(arr[start]) > abs(arr[end])) {
                ans[pos] = arr[start] * arr[start];
                pos--;
                start++;
            }           
            else {
                ans[pos] = arr[end] * arr[end];
                end--;
                pos--;
            } 
        }

        return ans;
    }
};