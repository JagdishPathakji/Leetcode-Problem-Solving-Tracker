class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() == 0)
        return 0;
        
        vector<int> v(256,0);

        int i = 0;
        int j = 0;

        int maxi = 0;
        
        while(j < s.size()) {

            while(v[s[j]]) {
                v[s[i]]--;
                i++;
            }

            v[s[j]]++;
            maxi = max(maxi,j-i+1);
            j++;
        }

        return maxi;//1
    }
};