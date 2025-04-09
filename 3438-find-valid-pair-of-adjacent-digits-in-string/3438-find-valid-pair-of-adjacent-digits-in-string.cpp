class Solution {
public:
    string findValidPair(string s) {
        
        int start = 0;
        int end = 1;

        while(end < s.size()) {

            if(s[start] != s[end]) {
                int count1 = 0;
                int count2 = 0;
                for(int i=0; i<s.size(); i++) {
                    if(s[i] == s[start]) 
                    count1++;
                    if(s[i] == s[end])
                    count2++;
                }

                if(count1 == s[start]-'0' and count2 == s[end]-'0') {
                    return string(1,s[start])+string(1,s[end]);
                }
            }

            start++;
            end++;
        }

        return "";
    }
};