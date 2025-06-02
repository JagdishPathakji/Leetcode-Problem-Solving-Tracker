class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        multiset<char> st;
        
        int i = 0;
        int j = 0;
        int maxwindowsize = INT_MIN;

        while(j < s.size()) {

            while(st.find(s[j]) != st.end()) {
                st.erase(st.find(s[i]));
                i++;
            }

            st.insert(s[j]);
            maxwindowsize = max(maxwindowsize,j-i+1);
            j++;
        }

        if(maxwindowsize == INT_MIN) return 0;
        return maxwindowsize;
    }
};