class NumArray {
public:

    vector<int> arr;
    vector<int> prefix;
    int total = 0;
    NumArray(vector<int>& nums) {
        arr = nums;
        prefix = vector<int>(nums.size());
        prefix[0] = arr[0];

        for(int i=1; i<nums.size(); i++) 
        prefix[i] = prefix[i-1]+arr[i];
    }
    
    void update(int index, int val) {
        
        int initialValue = arr[index];
        arr[index] = val;

        int diff = initialValue - val;
        diff = diff * (-1);

        for(int i=index; i<prefix.size(); i++)
        prefix[i] += diff;
    }
    
    int sumRange(int left, int right) {
       
        int total = prefix[right];

        int leftout = 0;
        if(left-1 >= 0)
        leftout = prefix[left-1];

        return total-leftout;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */