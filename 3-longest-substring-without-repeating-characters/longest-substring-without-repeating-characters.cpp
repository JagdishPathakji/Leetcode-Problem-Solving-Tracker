class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        if(s.size() == 0)
        return 0;
        
        set<char> st;

        int i = 0;
        int j = 0;

        int maxi = 0;
        while(j < s.size()) {

            while(i < j && st.find(s[j]) != st.end()) {
                st.erase(st.find(s[i]));
                i++;
            }
            
            st.insert(s[j]);
            maxi = maxi > st.size() ? maxi : st.size();
            j++;
        }

        return maxi;
    }
};