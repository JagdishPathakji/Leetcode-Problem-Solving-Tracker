class Solution {
public:
    int arraySign(vector<int>& nums) {
        
        long long x = 1;
        for(int i=0; i<nums.size(); i++) {
            x = (long long)(nums[i]) * x;
        }

        if(x > 0) return 1;
        else if(x == 0) return 0;
        else return -1;
    }
};