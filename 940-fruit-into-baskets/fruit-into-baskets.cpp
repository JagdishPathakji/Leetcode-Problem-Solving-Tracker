class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        
        unordered_map<int,int> mp;
        int i = 0;
        int j = 0;
        int n = fruits.size();
        int maxWindowSize = 0;
        int uniqnum = 0;

        while(j < n) {

            if(mp[fruits[j]] == 0) {
                uniqnum++;
            }

            if(uniqnum > 2) {
                while(uniqnum != 2) {
                    mp[fruits[i]]--;

                    if(mp[fruits[i]] == 0) 
                    uniqnum--;

                    i++;
                }
            }
            
            mp[fruits[j]]++;
        
            maxWindowSize = max(maxWindowSize,j-i+1);
            j++;
        }   

        return maxWindowSize;
    }
};