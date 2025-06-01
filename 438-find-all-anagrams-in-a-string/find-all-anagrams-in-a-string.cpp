class Solution {
public:

    bool allzero(vector<int> &freq) {
        for(int i=0; i<freq.size(); i++) {
            if(freq[i] != 0)
            return false;
        }

        return true;
    }

    vector<int> findAnagrams(string s, string p) {
        
        int windowsize = p.size();
        int n = s.size();
  
        vector<int> startofanagram;
        vector<int> freq(26,0);
  
        for(int i=0; i<p.size(); i++) 
        freq[p[i]-'a']++;

        int i = 0;
        int j = 0;

        while(j < n) {

            freq[s[j]-'a']--;

            if(j-i+1 == windowsize) {
                if(allzero(freq))
                startofanagram.push_back(i);

                freq[s[i]-'a']++;
                i++;
            }

            j++;
        }

        return startofanagram;
    }
};