class Solution {
public:
    string reverseWords(string s) {
        
        int j = s.size()-1;

        string ans = "";
        string temp = "";
        while(j >= 0) {
            
            while(j >= 0 and s[j] != ' ') {
                temp = s[j] + temp;
                j--;
            }

            if(temp != "") {
                temp += " ";
                ans = ans + temp;
                temp = "";
            }

            j--;
        }

        ans.pop_back();
        return ans;
    }
};