class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        
        vector<int> smaller;
        vector<int> greater;

        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            if(nums[i] < pivot) {
                smaller.push_back(nums[i]);
            }
            else if(nums[i] > pivot) {
                greater.push_back(nums[i]);
            }
            else {
                count++;
            }
        }

        while(count--)
        smaller.push_back(pivot);

        for(int i=0; i<greater.size(); i++)
        smaller.push_back(greater[i]);

        return smaller;
    }
};