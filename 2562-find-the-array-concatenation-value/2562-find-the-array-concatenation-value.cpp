class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        
        long long ans = 0;
        int i = 0;
        int j = nums.size()-1;
        while(i < j) {
            string temp = to_string(nums[i]) + to_string(nums[j]);
            ans += stoll(temp);
            i++;
            j--;
        
        }

        if(i == j) {
            ans = ans + nums[i];
        }

        return ans;
    }   
};