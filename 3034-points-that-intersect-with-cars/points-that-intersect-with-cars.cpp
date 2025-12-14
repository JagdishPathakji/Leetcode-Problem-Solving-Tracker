class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        
        sort(nums.begin(),nums.end());

        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            maxi = max(maxi,nums[i][0]);
            maxi = max(maxi,nums[i][1]);
        }

        vector<bool> visited(maxi+1,false);
        for(int i=0; i<nums.size(); i++) {
            int num1 = nums[i][0];
            int num2 = nums[i][1];

            for(int j=num1; j<=num2; j++) {
                visited[j] = true;
            }
        }

        int count = 0;
        for(int i=0; i<maxi+1; i++) {
            if(visited[i] == true)
            count++;
        }

        return count;
    }
};