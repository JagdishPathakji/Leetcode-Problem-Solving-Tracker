class Solution {
public:
    int maxDepth(string s) {
        
        if(s.size() == 1) return 0;

        int count = 0;
        int ans = INT_MIN;
        for(int i=0; i<s.size(); i++) {
            
            if(s[i] == '(') {
                count++;
                if(ans < count) {
                    ans = count;
                }
            }
            else if(s[i] == ')') {
                count--;
            }
        }

        if(ans == INT_MIN) return 0;
        return ans;
    }
};