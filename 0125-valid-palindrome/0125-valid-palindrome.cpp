class Solution {
public:
    bool isPalindrome(string s) {
        
        string ans = "";

        for(int i=0; i<s.size(); i++) {
            if(s[i] >= 'a' and s[i] <= 'z') {
                ans.push_back(s[i]);
            }
            else if(s[i] >= 'A' and s[i] <= 'Z') {
                ans.push_back(s[i]+32);
            }
            else if(s[i] >= '0' and s[i] <= '9') {
                ans.push_back(s[i]);
            }
        }


        string rev = ans;
        reverse(rev.begin(),rev.end());

        return (rev == ans);
    }
};