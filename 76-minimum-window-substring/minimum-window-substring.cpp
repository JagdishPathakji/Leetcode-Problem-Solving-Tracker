class Solution {
public:
    string minWindow(string s, string t) {
    
        int n = s.size();
        int m = t.size();

        if(m > n) return "";

        // storing the frequency
        unordered_map<char,int> mp;
        for(int i=0; i<t.size(); i++) 
        mp[t[i]]++;

        int requiredcount = t.size();
        int i = 0;
        int j = 0;
        int minwindowsize = INT_MAX;
        int final_start = 0;

        while(j < n) {

            char ch = s[j];
            if(mp[ch] > 0)
            requiredcount--;

            mp[ch]--;

            while(requiredcount == 0) {
                //start shrinking the window 
                int currwindowsize = j-i+1;
                if(minwindowsize > currwindowsize) {
                    final_start = i;
                    minwindowsize = currwindowsize;
                }

                mp[s[i]]++;
                if(mp[s[i]] > 0)
                requiredcount++;

                i++;
            }
            
            j++;
        }

        if(minwindowsize == INT_MAX) return "";
        return s.substr(final_start,minwindowsize);
    }
};