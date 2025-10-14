class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n=nums.size();
        vector<int>nums2(n);

        nums2[0] = nums[0];
        int j = 1;
        for(int i=1;i<n;i++)
        {   
            if(nums[i]!=nums[i-1])
            {
                nums2[j] = nums[i];
                j++;
            }
        }

        nums=nums2;
        return j;
        //Tc : O(n)
        //Sc : O(n)
    }
};