class Solution {
public:
    vector<string> partitionString(string s) {
        
        vector<string> ans;

        set<string> st;
        string curr = "";

        for(int i=0; i<s.size(); i++) {

            curr += s[i];
            if(st.find(curr) == st.end()) {
                ans.push_back(curr);
                st.insert(curr);
                curr = "";
            }
        }

        return ans;
    }
};