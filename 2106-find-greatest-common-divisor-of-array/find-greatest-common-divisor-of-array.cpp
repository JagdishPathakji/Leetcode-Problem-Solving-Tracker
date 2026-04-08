class Solution {
public:

    int findGCD(vector<int>& nums) {
        
        int smallest =  nums[0];
        int largest = nums[0];
    
        for(int i=0; i<nums.size(); i++) {
            smallest = min(smallest,nums[i]);
            largest = max(largest,nums[i]);
        }

        for(int i=largest; i>=1; i--) {
            if(largest % i == 0 && smallest % i == 0)
            return i;
        }

        return -1;
    }
};