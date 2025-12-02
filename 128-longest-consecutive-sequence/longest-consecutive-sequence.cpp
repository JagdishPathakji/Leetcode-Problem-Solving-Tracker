class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        if(nums.size() == 0)
        return 0;

        sort(nums.begin(),nums.end());

        int num = nums[0];
        int ans = 1;
        int real = 1;

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] == num) continue;
            if(nums[i]-num == 1) {
                ans++;
            }
            else {
                real = max(real,ans);
                ans = 1;
            }
            
            num = nums[i];
        }

        real = max(real,ans);
        return real;
    }
};