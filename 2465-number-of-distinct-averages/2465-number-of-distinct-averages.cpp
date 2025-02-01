class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        
        if(nums.size() == 2) {
            return 1;
        }

        sort(nums.begin(),nums.end());
        int start = 0;
        int end = nums.size()-1;
        vector<double> v;
        while(start < end) {

            v.push_back((double(nums[start])+double(nums[end]))/2);
            start++;
            end--;
        }

        int count = 1;

        sort(v.begin(),v.end());
        for(int i=1; i<v.size(); i++) {
            if(v[i] != v[i-1]) {
                count++;
            }
        }

        return count;
    }
};