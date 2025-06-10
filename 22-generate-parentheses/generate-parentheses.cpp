class Solution {
public:

    void find(int &n, int left, int right, vector<string> &ans, string &temp) {

        if(left > n or right > n) {
            return;
        }

        if(right > left) {
            return;
        }

        if(left == n and right == n) {
            ans.push_back(temp);
            return;
        }

        temp.push_back('(');
        find(n,left+1,right,ans,temp);
        temp.pop_back();

        temp.push_back(')');
        find(n,left,right+1,ans,temp);
        temp.pop_back();

    }

    vector<string> generateParenthesis(int n) {
        
        vector<string> ans;
        string temp = "";
        find(n,0,0,ans,temp);

        return ans;
    }
};