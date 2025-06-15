class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        // atleast(k) - atleast(k+1)
        // atmost(k) - atmost(k-1)

        int i = 0;
        int j = 0;

        int total1 = 0;
        int uniqueelements = 0;
        unordered_map<int,int> mp;

        while(j < nums.size()) {
            
            if(mp[nums[j]] == 0) {
                uniqueelements++;
            }

            mp[nums[j]]++;

            while(uniqueelements == k) {
                total1 += nums.size()-j;
                if(mp[nums[i]] == 1) {
                    uniqueelements--;
                }
                mp[nums[i]]--;
                i++;
            }

            j++;
        }

        int total2 = 0;
        uniqueelements = 0;
        mp.clear();

        i = 0;
        j = 0;

        while(j < nums.size()) {
            
            if(mp[nums[j]] == 0) {
                uniqueelements++;
            }

            mp[nums[j]]++;

            while(uniqueelements == k+1) {
                total2 += nums.size()-j;
                if(mp[nums[i]] == 1) {
                    uniqueelements--;
                }
                mp[nums[i]]--;
                i++;
            }

            j++;
        }


        return total1-total2;
    }
};