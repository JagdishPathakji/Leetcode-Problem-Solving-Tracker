class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int carry = 1;
        vector<int> ans;
        for(int i=digits.size()-1; i>=0; i--) {
            int sum = digits[i]+carry;
            int num = sum % 10;
            carry = sum / 10;
            ans.push_back(num);
        }

        if(carry)
        ans.push_back(1);
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};