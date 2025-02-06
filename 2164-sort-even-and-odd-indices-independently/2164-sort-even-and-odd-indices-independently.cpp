class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        
        vector<int> v1;
        vector<int> v2;

        for(int i=0; i<nums.size(); i=i+2) {
            v1.push_back(nums[i]);
        }

        for(int i=1; i<nums.size(); i=i+2) {
            v2.push_back(nums[i]);
        }

        sort(v1.begin(),v1.end());
        sort(v2.rbegin(),v2.rend());

        int j = 0;
        int k = 0;

        for(int i=0; i<nums.size(); i++) {
            if(i%2 == 0) {
                nums[i] = v1[j];
                j++;
            }
            else {
                nums[i] = v2[k];
                k++;
            }
        }

        return nums;
    }
};