class Solution {
public:
    vector<int> partitionLabels(string s) {
        
        vector<int> v(26,0);
        for(int i=0; i<s.size(); i++) {
            v[s[i]-'a'] = i;
        }

        int i = 0;
        vector<int> v1;
        while(true) {
            
            if(i >= s.size()) break;

            int k = i;
            int j = v[s[i]-'a'];
            while(k <= j) {

                if(v[s[k]-'a'] > j) {
                    j = v[s[k]-'a'];
                }
                k++;
            }

            v1.push_back(j-i+1);
            i = j+1;
        }

        return v1;
    }
};