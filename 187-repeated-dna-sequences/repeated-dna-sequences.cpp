class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        int k = 10;
        unordered_set<string> us;
        
        string firstwindow = s.substr(0,10);
        us.insert(firstwindow);

        int idx = 1;
        set<vector<string>> ans1;

        // check for every window of size k and get that string
        // after that check if string already seen, if yes store it
        // after that if string not already seen, make it as seen using map
        // at the end , we will have all 10len strings which are repeated atleast once.
        // return them

        for(int i=k; i<s.size(); i++) {
            string str = s.substr(idx,k);
            idx++;

            if(us.find(str) != us.end()) {
                ans1.insert({str});
            }
            else {
                us.insert(str);
            }
        }

        vector<string> ans;
        for(auto it : ans1) {
            ans.push_back(it[0]);
        }
        return ans;
    }
};