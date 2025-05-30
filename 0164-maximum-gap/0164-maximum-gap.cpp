class Solution {
public:
    int maximumGap(vector<int>& nums) {
        
        if(nums.size() == 1) {
            return 0;
        }

        int maxi = 0;
        sort(nums.begin(),nums.end());

        for(int i=0; i<nums.size()-1; i++) {
            maxi = max(maxi,(nums[i+1]-nums[i]));
        }

        return maxi;
    }
};