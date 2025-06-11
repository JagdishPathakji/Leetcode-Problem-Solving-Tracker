class Solution {
public:

    void find(vector<int> &nums, set<vector<int>> &s, int index, vector<int> &temp) {

        if(index >= nums.size()) {
            s.insert(temp);
            return;
        }

        temp.push_back(nums[index]);
        find(nums,s,index+1,temp);
        temp.pop_back();
        find(nums,s,index+1,temp);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        set<vector<int>> s;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        find(nums,s,0,temp);

        vector<vector<int>> ans(s.begin(),s.end());
        return ans;
    }
};