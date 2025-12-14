class NumArray {
public:

    vector<int> arr;
    vector<int> prefix;
    NumArray(vector<int>& nums) {
        arr = nums;
        prefix = vector<int>(nums.size());

        prefix[0] = nums[0];
        for(int i=1; i<nums.size(); i++) {
            prefix[i] = prefix[i-1] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right]-prefix[left]+arr[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */