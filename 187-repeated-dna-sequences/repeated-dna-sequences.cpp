class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        
        int k = 10;
        unordered_set<string> us;
        
        string firstwindow = s.substr(0,10);
        cout<<firstwindow<<endl;
        us.insert(firstwindow);

        int idx = 1;
        set<vector<string>> ans1;
        for(int i=k; i<s.size(); i++) {
            string str = s.substr(idx,k);
            idx++;
            cout<<str<<endl;
            if(us.find(str) != us.end()) {
                ans1.insert({str});
            }
            us.insert(str);
        }

        vector<string> ans;
        for(auto it : ans1) {
            ans.push_back(it[0]);
        }
        return ans;
    }
};