class Solution {
public:

    void find(vector<int> &arr, int index, vector<vector<int>> &ans, int &target, int &sum, vector<int> &temp) {

        if(sum > target) return;

        if(index >= arr.size()) {
            if(target == sum) {
                ans.push_back(temp);
            }
            return;
        }

        temp.push_back(arr[index]);
        sum += arr[index];
        find(arr,index,ans,target,sum,temp);
        
        temp.pop_back();
        sum -= arr[index];
        find(arr,index+1,ans,target,sum,temp);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        int sum = 0;
        vector<int> temp;
        find(candidates,0,ans,target,sum,temp);

        return ans;
    }
};