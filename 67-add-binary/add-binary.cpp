class Solution {
public:
    string addBinary(string a, string b) {
        
        string ans = "";

        int i = a.size()-1;
        int j = b.size()-1;

        int carry = 0;
        while(i >= 0 && j >= 0) {

            int sum = (a[i]-'0') + (b[j]-'0') + carry;
            if(sum <= 1) {
                ans.push_back(sum+'0');
                carry = 0;
            }
            else if(sum == 2) {
                ans.push_back('0');
                carry = 1;
            }
            else if(sum == 3) {
                ans.push_back('1');
                carry = 1;
            }

            i--;
            j--;
        }
        
        while(i >= 0) {
            int sum = (a[i]-'0') + carry;
            if(sum <= 1) {
                ans.push_back(sum+'0');
                carry = 0;
            }
            else if(sum == 2) {
                ans.push_back('0');
                carry = 1;
            }
            i--;
        }

        while(j >= 0) {
            int sum = (b[j]-'0') + carry;
            if(sum <= 1) {
                ans.push_back(sum+'0');
                carry = 0;
            }
            else if(sum == 2) {
                ans.push_back('0');
                carry = 1;
            }
            j--;
        }

        if(carry) {
            ans.push_back('1');
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};