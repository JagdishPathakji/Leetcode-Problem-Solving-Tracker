class Solution {
public:
    int reverseDegree(string s) {
        
        int ans = 0;
        for(int i=0; i<s.size(); i++) {
            ans = ans + ('a'-s[i]+26)*(i+1);
        }

        return ans;
    } 
};