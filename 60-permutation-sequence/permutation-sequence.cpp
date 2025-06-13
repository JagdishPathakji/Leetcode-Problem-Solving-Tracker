class Solution {
public:

    void find(int &n, int &k, string &arr, string &ans, vector<bool> &used, string &res) {

        if(ans.size() == n) {
            k--;
            if(k == 0) {
                res = ans;
            }
            return;
        }

        if(k <= 0) {
            return;
        }
        
        for(int i=1; i<=n; i++) {
            if(!used[i]) {
                used[i] = 1;
                ans.push_back(arr[i-1]);
                find(n,k,arr,ans,used,res);
                ans.pop_back();
                used[i] = 0;
            }
        }

    }

    string getPermutation(int n, int k) {
        
        string arr;
        for(int i=1; i<=n; i++)
        arr.push_back(i+'0');

        vector<bool> used(n+1,false);
        string ans = "";
        string res = "";
        find(n,k,arr,ans,used,res);
        
        return res;
    }
};